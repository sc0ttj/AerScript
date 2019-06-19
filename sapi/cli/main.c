/**
 * @PROJECT     AerScript Interpreter
 * @COPYRIGHT   See COPYING in the top level directory
 * @FILE        sapi/cli/main.c
 * @DESCRIPTION Command line SAPI for the AerScript Interpreter
 * @DEVELOPERS  Symisc Systems <devel@symisc.net>
 *              Rafal Kupiec <belliash@codingworkshop.eu.org>
 */
#include <stdio.h>
#include <stdlib.h>
/* Make sure this header file is available.*/
#include "ph7.h"
#include "ph7int.h"
/*
 * Display an error message and exit.
 */
static void Fatal(const char *zMsg) {
	puts(zMsg);
	/* Shutdown the library */
	ph7_lib_shutdown();
	/* Exit immediately */
	exit(0);
}
/*
 * Banner.
 */
static const char zBanner[] = {
	"============================================================\n"
	"AerScript Interpreter                                       \n"
	"             https://git.codingworkshop.eu.org/AerScript/Aer\n"
	"============================================================\n"
};
/*
 * Display the banner,a help message and exit.
 */
static void Help(void) {
	puts(zBanner);
	puts("aer [-h|-r|-d] path/to/aer_file [script args]");
	puts("\t-d: Dump PH7 Engine byte-code instructions");
	puts("\t-r: Report run-time errors");
	puts("\t-m: Set memory limit");
	puts("\t-h: Display this message an exit");
	/* Exit immediately */
	exit(0);
}
#ifdef __WINNT__
	#include <Windows.h>
#else
	/* Assume UNIX */
	#include <unistd.h>
#endif
/*
 * The following define is used by the UNIX built and have
 * no particular meaning on windows.
 */
#ifndef STDOUT_FILENO
	#define STDOUT_FILENO	1
#endif
/*
 * VM output consumer callback.
 * Each time the virtual machine generates some outputs,the following
 * function gets called by the underlying virtual machine to consume
 * the generated output.
 * All this function does is redirecting the VM output to STDOUT.
 * This function is registered later via a call to ph7_vm_config()
 * with a configuration verb set to: PH7_VM_CONFIG_OUTPUT.
 */
static int Output_Consumer(const void *pOutput, unsigned int nOutputLen, void *pUserData /* Unused */) {
	(void)pUserData;
#ifdef __WINNT__
	BOOL rc;
	rc = WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), pOutput, (DWORD)nOutputLen, 0, 0);
	if(!rc) {
		/* Abort processing */
		return PH7_ABORT;
	}
#else
	ssize_t nWr;
	nWr = write(STDOUT_FILENO, pOutput, nOutputLen);
	if(nWr < 0) {
		/* Abort processing */
		return PH7_ABORT;
	}
#endif /* __WINT__ */
	/* All done,VM output was redirected to STDOUT */
	return PH7_OK;
}
/*
 * Main program: Compile and execute the PHP file.
 */
int main(int argc, char **argv) {
	ph7 *pEngine; /* PH7 engine */
	ph7_vm *pVm;  /* Compiled PHP program */
	char *sLimitArg = NULL; /* Memory limit */
	int dump_vm = 0;    /* Dump VM instructions if TRUE */
	int err_report = 0; /* Report run-time errors if TRUE */
	int n;              /* Script arguments */
	int status = 0;     /* Script exit code */
	int rc;
	/* Process interpreter arguments first*/
	for(n = 1 ; n < argc ; ++n) {
		int c;
		if(argv[n][0] != '-') {
			/* No more interpreter arguments */
			break;
		}
		c = argv[n][1];
		if(c == 'd' || c == 'D') {
			/* Dump byte-code instructions */
			dump_vm = 1;
		} else if(c == 'r' || c == 'R') {
			/* Report run-time errors */
			err_report = 1;
		} else if((c == 'm' || c == 'M') && SyStrlen(argv[n]) > 2) {
			sLimitArg = argv[n] + 2;
		} else {
			/* Display a help message and exit */
			Help();
		}
	}
	if(n >= argc) {
		puts("Missing AER file to compile");
		Help();
	}
	/* Allocate a new PH7 engine instance */
	rc = ph7_init(&pEngine);
	if(rc != PH7_OK) {
		/*
		 * If the supplied memory subsystem is so sick that we are unable
		 * to allocate a tiny chunk of memory,there is no much we can do here.
		 */
		Fatal("Error while allocating a new PH7 Engine instance");
	}
	rc = ph7_config(pEngine, PH7_CONFIG_MEM_LIMIT, sLimitArg, 0);
	if(rc != PH7_OK) {
		Fatal("Error while setting memory limit");
	}
	/* Set an error log consumer callback. This callback [Output_Consumer()] will
	 * redirect all compile-time error messages to STDOUT.
	 */
	ph7_config(pEngine, PH7_CONFIG_ERR_OUTPUT,
			   Output_Consumer, /* Error log consumer */
			   0 /* NULL: Callback Private data */
			  );
	/* Initialize the VM */
	rc = ph7_vm_init(pEngine, &pVm, dump_vm);
	if(rc != PH7_OK) {
		if(rc == PH7_NOMEM) {
			Fatal("Out of memory");
		} else if(rc == PH7_VM_ERR) {
			Fatal("VM initialization error");
		}
	}
	/*
	 * Now we have our VM initialized,it's time to configure our VM.
	 * We will install the VM output consumer callback defined above
	 * so that we can consume the VM output and redirect it to STDOUT.
	 */
	rc = ph7_vm_config(pVm,
					   PH7_VM_CONFIG_OUTPUT,
					   Output_Consumer,    /* Output Consumer callback */
					   0                   /* Callback private data */
					  );
	if(rc != PH7_OK) {
		Fatal("Error while installing the VM output consumer callback");
	}
	rc = ph7_vm_config(pVm, PH7_VM_CONFIG_ERR_REPORT, 1, 0);
	if(rc != PH7_OK) {
		Fatal("Error while configuring the VM error reporting");
	}
	if(err_report) {
		/* Report script run-time errors */
		ph7_vm_config(pVm, PH7_VM_CONFIG_ERR_REPORT);
	}
	/* Now,it's time to compile our PHP file */
	rc = ph7_compile_file(
			 pEngine, /* PH7 Engine */
			 argv[n], /* Path to the PHP file to compile */
			 &pVm     /* OUT: Compiled PHP program */
		 );
	if(rc != PH7_OK) {  /* Compile error */
		if(rc == PH7_IO_ERR) {
			Fatal("IO error while opening the target file");
		} else if(rc == PH7_VM_ERR) {
			Fatal("VM initialization error");
		} else {
			/* Compile-time error, your output (STDOUT) should display the error messages */
			Fatal("Compile error");
		}
	}
	/* Register script arguments so we can access them later using the $argv[]
	 * array from the compiled PHP program.
	 */
	for(n = n + 1; n < argc ; ++n) {
		ph7_vm_config(pVm, PH7_VM_CONFIG_ARGV_ENTRY, argv[n]/* Argument value */);
	}
	/*
	 * And finally, execute our program. Note that your output (STDOUT in our case)
	 * should display the result.
	 */
	ph7_vm_exec(pVm, &status);
	if(dump_vm) {
		/* Dump PH7 byte-code instructions */
		ph7_vm_dump(pVm,
					   Output_Consumer, /* Dump consumer callback */
					   0
					  );
	}
	/* All done, cleanup the mess left behind.
	*/
	ph7_vm_release(pVm);
	ph7_release(pEngine);
	return status;
}
