#include <stdio.h>
#include <stdlib.h>

#include <execlight26.h>

#ifndef _WIN32
#include <unistd.h>
#include <sys/wait.h>
#include <spawn.h>
#else
#include <windows.h>
#endif

#ifndef _WIN32
int LightExec(char* const* argv) {
		
		pid_t child_pid;
		int ret = posix_spawnp(&child_pid, argv[0], NULL, NULL, argv, environ);

	//	for (int i = 0; i < sizeof(argv) / sizeof(argv[0]); i++) {
	//		printf("%s\n", argv[i]);
	//	}

		if (ret != 0) {
			printf("[Light26] POSIX EXECUTION FAILED; RETURNED CODE %d;\n", ret);
			printf("%s\n", argv[0]);
			return 1;
		}
		int wstatus;
		printf("process 0\n");
		if (waitpid(child_pid, &wstatus, WUNTRACED) == -1) {
			perror("[Light26] WAITPID FAILED; RETURNED -1;");
			printf(" RETURNED STATUS %d;", wstatus);
		} else {
			if (WIFSIGNALED(wstatus)) {
				printf("[Light] SIGNALED WAITPID STATUS: %d\n", WTERMSIG(wstatus));
			}
		};
	return 0;
}
#else
int LightExec(wchar_t* argv) {
	STARTUPINFOW startupinfoWchar;
	PROCESS_INFORMATION process_informationWchar;

	if (!CreateProcessW(NULL, argv, NULL, NULL, false, 0, NULL, NULL, &startupinfoWchar, &process_informationWchar)) {
		printf("[Light26] WINDOWS EXECUTION FAILED; RETURNED %lu\n", (long unsigned)GetLastError());
		return 1;
	}
	
	if (WaitForSingleObject(process_informationWchar.hProcess, INFINITE) == WAIT_FAILED) {
		printf("[Light26] Did not return WAIT_OBJECT_0\n");
		printf("[Light26] WAITFORSINGLEOBJECT FAILED RETURNED %lu\n", (long unsigned)GetLastError());
		return 1;
	}
	
	CloseHandle(startupinfoWchar.hProcess);
	CloseHandle(process_informationWchar.hThread);
	return 0;
}
#endif
