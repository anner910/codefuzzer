#include "../core/Core.h"

#include <signal.h>
#include <errno.h>


#ifdef __cplusplus
extern "C"{
#endif

#ifdef CF_Mode_Crash

#ifndef _WIN32

void SetSigaction(int signum, void (*callback)(int, siginfo_t *, void *)) 
{
  struct sigaction sigact = {};
  if (sigaction(signum, NULL, &sigact)) {
    PL_printf("libFuzzer: sigaction failed with %d\n", errno);
    PL_exit(1);
  }
  if (sigact.sa_flags & SA_SIGINFO) {
    if (sigact.sa_sigaction)
      return;
  } else {
    if (sigact.sa_handler != SIG_DFL && sigact.sa_handler != SIG_IGN &&
        sigact.sa_handler != SIG_ERR)
      return;
  }

  //sigact = {};
  sigact.sa_sigaction = callback;
  if (sigaction(signum, &sigact, 0)) {
    PL_printf("libFuzzer: sigaction failed with %d\n", errno);
    PL_exit(1);
  }
}



void CrashHandler(int aaa, siginfo_t * bbb, void * ccc) 
{ 
	char* reason;
	if (aaa == SIGALRM)
	{
		PL_printf("\r\nCrashHandler because timeout \r\n");
		reason = "time out";

	}
	else if (aaa == SIGSEGV)
	{
		PL_printf("\r\nCrashHandler because SIGSEGV \r\n");
		reason = "SIGSEGV";

	}
	else if (aaa == SIGBUS)
	{
		PL_printf("\r\nCrashHandler because SIGBUS \r\n");
		reason = "SIGBUS";

	}
	else if (aaa == SIGABRT)
	{
		PL_printf("\r\nCrashHandler because SIGABRT \r\n");
		reason = "SIGABRT";

	}
	else if (aaa == SIGILL)
	{
		PL_printf("\r\nCrashHandler because SIGILL \r\n");
		reason = "SIGILL";

	}
	else if (aaa == SIGFPE)
	{
		PL_printf("\r\nCrashHandler because SIGFPE \r\n");
		reason = "SIGFPE";
	}
	else
	{
		PL_printf("\r\nCrashHandler because other \r\n");
		reason = "other";
	}

	report_andCrashWrite(reason);

	if (__sanitizer_print_stack_trace)
	{
		PL_printf("\r\n-----Codefuzzer PL_printf stack trace start\r\n");
		__sanitizer_print_stack_trace();
		PL_printf("\r\n------Codefuzzer PL_printf stack trace end\r\n");
	}

	PL_exit(Exit_No_Crash);
}

#endif

void ExitHandler(void) 
{ 
	PL_printf("\r\nCodefuzzer exit-----------crash is %d----@@@@@@@\r\n",g_thread.isHasCrash);

	//主动推出
	if (g_thread.isSelfExit)
		PL_exit(0);
	else
		PL_exit(1);
	

}
void SetSignalHandler(void) 
{

	if(g_global.isSignalInit == 0)
		g_global.isSignalInit = 1;
	else
		return;

#ifndef _WIN32
	SetSigaction(SIGALRM, CrashHandler);
    SetSigaction(SIGSEGV, CrashHandler);
    SetSigaction(SIGBUS, CrashHandler);
    SetSigaction(SIGABRT, CrashHandler);
    SetSigaction(SIGILL, CrashHandler);
    SetSigaction(SIGFPE, CrashHandler);
#endif

	if(__asan_set_error_report_callback)
		__asan_set_error_report_callback(report_asan);

	 atexit(ExitHandler);
}

#else
void SetSignalHandler(void) 
{

}
#endif


#ifdef __cplusplus
}
#endif


