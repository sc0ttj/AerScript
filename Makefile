# Flags to pass to the compiler
CFLAGS = -fPIC -Iinclude -I. -W -Wunused -Wall

# Additional CFLAGS for debug build
DCFLAGS = -O0 -g3 -fsplit-stack

# Addditional CFLAGS for release build
RCFLAGS = -O3 -s

# Flags to pass to the linker
LDFLAGS =

# Destination directory
DESTDIR ?= $(realpath .)/binary

##############################################
### Do not modify anything below this line ###
##############################################
ifeq ($(OS),Windows_NT)
	PLATFORM := Windows
else
	PLATFORM := $(shell uname -s)
endif

ifeq "$(PLATFORM)" "Darwin"
	CC := clang
	CP := cp -v
	MD := mkdir -p
	RM := rm -rfv
	LDFLAGS := $(LDFLAGS) -Wl,-export_dynamic -undefined dynamic_lookup
	LIBS := -ldl -lm
	EXESUFFIX :=
	LIBSUFFIX := .dylib
endif
ifeq "$(PLATFORM)" "FreeBSD"
	CC := clang
	CP := cp -v
	MD := mkdir -p
	RM := rm -rfv
	LDFLAGS := $(LDFLAGS) -Wl,--export-dynamic
	LIBS := -lm
	EXESUFFIX :=
	LIBSUFFIX := .so
endif
ifeq "$(PLATFORM)" "Linux"
	CC := gcc
	CP := cp -v
	MD := mkdir -p
	RM := rm -rfv
	LDFLAGS := $(LDFLAGS) -Wl,--export-dynamic
	LIBS := -ldl -lm
	EXESUFFIX :=
	LIBSUFFIX := .so
endif
ifeq "$(PLATFORM)" "OpenBSD"
	CC := clang
	CP := cp -v
	MD := mkdir -p
	RM := rm -rfv
	LDFLAGS := $(LDFLAGS) -Wl,--export-dynamic
	LIBS := -lm
	EXESUFFIX :=
	LIBSUFFIX := .so
endif
ifeq "$(PLATFORM)" "Windows"
	CC := gcc
	CP := copy
	MD := md
	RM := del /F
	LDFLAGS := $(LDFLAGS) -Wl,--export-all-symbols
	LIBS :=
	EXESUFFIX := .exe
	LIBSUFFIX := .dll
endif

ASTYLE_FLAGS =\
	--style=java \
	--indent=force-tab \
	--attach-closing-while \
	--attach-inlines \
	--attach-classes \
	--indent-classes \
	--indent-modifiers \
	--indent-switches \
	--indent-cases \
	--indent-preproc-block \
	--indent-preproc-define \
	--indent-col1-comments \
	--pad-oper \
	--pad-comma \
	--unpad-paren \
	--delete-empty-lines \
	--align-pointer=name \
	--align-reference=name \
	--break-one-line-headers \
	--add-braces \
	--verbose \
	--formatted \
	--lineend=linux

BINARY := aer
BUILD_DIR := build
CFLAGS := $(CFLAGS) -DPH7_LIBRARY_SUFFIX=\"$(LIBSUFFIX)\"
LIBFLAGS := -Wl,-rpath,$(DESTDIR) -L$(BUILD_DIR) -l$(BINARY)

ENGINE_DIRS := engine/lib engine
ENGINE_SRCS := $(foreach dir,$(ENGINE_DIRS),$(wildcard $(dir)/*.c))
ENGINE_MAKE := $(ENGINE_SRCS:.c=.o)
ENGINE_OBJS := $(addprefix $(BUILD_DIR)/,$(ENGINE_MAKE))

MODULE := $(subst /,,$(subst modules/,,$(dir $(wildcard modules/*/))))
SAPI := $(subst /,,$(subst sapi/,,$(dir $(wildcard sapi/*/))))

TEST_DIR := tests
TEST_EXT := aer
TESTS := $(subst .$(TEST_EXT),.test,$(wildcard $(TEST_DIR)/*.$(TEST_EXT)))


.SUFFIXES:
.PHONY: clean debug install release style tests

debug: export CFLAGS := $(CFLAGS) $(DCFLAGS)
debug: engine sapi modules
release: export CFLAGS := $(CFLAGS) $(RCFLAGS)
release: engine sapi modules

engine: $(ENGINE_OBJS)
	$(CC) -o $(BUILD_DIR)/lib$(BINARY)$(LIBSUFFIX) $(LDFLAGS) $(LIBS) -shared $(ENGINE_OBJS)

modules: $(MODULE)

sapi: $(SAPI)

$(BUILD_DIR)/%.o: %.c
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(MODULE):
	$(eval MODULE_DIRS := $@)
	$(eval MODULE_SRCS := $(foreach dir,modules/$(MODULE_DIRS),$(wildcard $(dir)/*.c)))
	$(eval MODULE_MAKE := $(MODULE_SRCS:.c=.o))
	$(eval MODULE_OBJS := $(addprefix $(BUILD_DIR)/,$(MODULE_MAKE)))
	$(eval MODULE_PROG := $(MODULE_DIRS)$(LIBSUFFIX))
	$(MAKE) $(MODULE_OBJS)
	$(CC) -o $(BUILD_DIR)/$(MODULE_PROG) $(LDFLAGS) -shared $(MODULE_OBJS)

$(SAPI):
	$(eval SAPI_DIRS := $@)
	$(eval SAPI_SRCS := $(foreach dir,sapi/$(SAPI_DIRS),$(wildcard $(dir)/*.c)))
	$(eval SAPI_MAKE := $(SAPI_SRCS:.c=.o))
	$(eval SAPI_OBJS := $(addprefix $(BUILD_DIR)/,$(SAPI_MAKE)))
	$(eval SAPI_PROG := $(subst -cli,,$(BINARY)-$(SAPI_DIRS))$(EXESUFFIX))
	$(MAKE) $(SAPI_OBJS)
	$(CC) -o $(BUILD_DIR)/$(SAPI_PROG) $(LDFLAGS) $(LIBFLAGS) $(SAPI_OBJS)

%.test: %.exp %.$(TEST_EXT)
	@$(MD) ${BUILD_DIR}/${TEST_DIR}
	@echo -n "Executing test: $*.$(TEST_EXT) ... "
	@if [ "x`echo $* | grep args`" != "x" ]; \
	then \
		binary/$(BINARY)$(EXESUFFIX) $*.$(TEST_EXT) - arg1 arg2 arg3 arg4 2>&1 >$(BUILD_DIR)/$*.out; \
	else \
		binary/$(BINARY)$(EXESUFFIX) $*.$(TEST_EXT) 2>&1 >$(BUILD_DIR)/$*.out; \
	fi
	@if [ "x`diff -qbu $*.exp $(BUILD_DIR)/$*.out`" != "x" ]; \
	then \
		echo "ERROR!"; \
		diff -u $*.exp $(BUILD_DIR)/$*.out; \
		rm -f $(BUILD_DIR)/$(TEST_DIR)/*.out \
		exit 1; \
	fi;
	@rm -f $(BUILD_DIR)/$(TEST_DIR)/*.out
	@echo "OK!"

clean:
	$(RM) $(BUILD_DIR)

install: engine modules sapi
	$(MD) $(DESTDIR)
	$(CP) $(BUILD_DIR)/$(BINARY)* $(DESTDIR)/
	$(CP) $(BUILD_DIR)/*$(LIBSUFFIX) $(DESTDIR)/

style:
	astyle $(ASTYLE_FLAGS) --recursive ./*.c,*.h

tests: $(TESTS)
