# Flags to pass to the compiler
CFLAGS = -fPIC -Iinclude -I. -W -Wunused -Wall

# Additional CFLAGS for debug build
DFLAGS = -O0 -g

# Addditional CFLAGS for release build
RFLAGS = -O3 -s

# Flags to pass to the linker
LFLAGS = -Wl,--export-dynamic -rdynamic

# Additional libraries necessary for linker
LIBS = -ldl -lm

##############################################
### Do not modify anything below this line ###
##############################################
ifeq ($(OS),Windows_NT)
	PLATFORM := "Windows"
else
	PLATFORM := $(shell uname -s)
endif

ifeq "$(PLATFORM)" "Darwin"
	CC := clang
	MD := mkdir -p
	RM := rm -rfv
	ESUFFIX :=
	LSUFFIX := .dylib
endif
ifeq "$(PLATFORM)" "FreeBSD"
	CC := clang
	MD := mkdir -p
	RM := rm -rfv
	ESUFFIX :=
	LSUFFIX := .so
  LIBS = -lm
endif
ifeq "$(PLATFORM)" "Linux"
	CC := gcc
	MD := mkdir -p
	RM := rm -rfv
	ESUFFIX :=
	LSUFFIX := .so
endif
ifeq "$(PLATFORM)" "OpenBSD"
	CC := clang
	MD := mkdir -p
	RM := rm -rfv
	ESUFFIX :=
	LSUFFIX := .so
  LIBS = -lm
endif
ifeq "$(PLATFORM)" "Windows"
	CC := gcc
	MD := md
	RM := del /F
	ESUFFIX := .exe
	LSUFFIX := .dll
endif

BINARY := psharp
BUILD_DIR := build
CFLAGS := $(CFLAGS) -DPH7_LIBRARY_SUFFIX=\"$(LSUFFIX)\"

ENGINE_DIRS := engine/lib engine
ENGINE_SRCS := $(foreach dir,$(ENGINE_DIRS),$(wildcard $(dir)/*.c))
ENGINE_MAKE := $(ENGINE_SRCS:.c=.o)
ENGINE_OBJS := $(addprefix $(BUILD_DIR)/,$(ENGINE_MAKE))

MODULE := $(subst /,,$(subst modules/,,$(dir $(wildcard modules/*/))))
SAPI := $(subst /,,$(subst sapi/,,$(dir $(wildcard sapi/*/))))


.SUFFIXES:
.PHONY: clean debug release style test

debug: export CFLAGS := $(CFLAGS) $(DFLAGS)
debug: engine sapi module
release: export CFLAGS := $(CFLAGS) $(RFLAGS)
release: engine sapi module

engine: $(ENGINE_OBJS)

module: $(MODULE)

sapi: $(SAPI)

$(BUILD_DIR)/%.o: %.c
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(MODULE):
	$(eval MODULE_DIRS := $@)
	$(eval MODULE_SRCS := $(foreach dir,modules/$(MODULE_DIRS),$(wildcard $(dir)/*.c)))
	$(eval MODULE_MAKE := $(MODULE_SRCS:.c=.o))
	$(eval MODULE_OBJS := $(addprefix $(BUILD_DIR)/,$(MODULE_MAKE)))
	$(eval MODULE_PROG := $(MODULE_DIRS)$(LSUFFIX))
	$(MAKE) $(MODULE_OBJS)
	$(CC) -o $(BUILD_DIR)/$(MODULE_PROG) $(LFLAGS) $(LIBS) -shared $(MODULE_OBJS)

$(SAPI):
	$(eval SAPI_DIRS := $@)
	$(eval SAPI_SRCS := $(foreach dir,sapi/$(SAPI_DIRS),$(wildcard $(dir)/*.c)))
	$(eval SAPI_MAKE := $(SAPI_SRCS:.c=.o))
	$(eval SAPI_OBJS := $(addprefix $(BUILD_DIR)/,$(SAPI_MAKE)))
	$(eval SAPI_PROG := $(subst -cli,,$(BINARY)-$(SAPI_DIRS))$(ESUFFIX))
	$(MAKE) $(SAPI_OBJS)
	$(CC) -o $(BUILD_DIR)/$(SAPI_PROG) $(LFLAGS) $(LIBS) $(ENGINE_OBJS) $(SAPI_OBJS)

clean:
	$(RM) $(BUILD_DIR)
