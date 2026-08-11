#include <stdio.h>
#include <stdlib.h>

#include <lightexe.h>

#ifndef _WIN32
#include <unistd.h>
#include <sys/wait.h>
#include <spawn.h>
#else
#include <windows.h>
#endif

int spawnexee(char* const* argv) {
#ifdef _WIN32

#else
		
		pid_t child_pid;
		int ret = posix_spawnp(&child_pid, argv[0], NULL, NULL, argv, environ);

	//	for (int i = 0; i < sizeof(argv) / sizeof(argv[0]); i++) {
	//		printf("%s\n", argv[i]);
	//	}

		if (ret != 0) {
			printf("{Light] POSIX EXECUTION FAILED; RETURNED CODE %d;\n", ret);
			printf("%s\n", argv[0]);
			return 1;
		}
		int wstatus;
		printf("process 0\n");
		if (waitpid(child_pid, &wstatus, WUNTRACED) == -1) {
			perror("[Light] WAITPID FAILED; RETURNED -1;");
			printf(" RETURNED STATUS %d;", wstatus);
		} else {
			if (WIFSIGNALED(wstatus)) {
				printf("[Light] SIGNALED WAITPID STATUS: %d\n", WTERMSIG(wstatus));
				printf("%s, %s, %s\n", argv[0], argv[1], argv[2]);
			}
		};

#endif
	return 0;
}

void LIGstrinit(ligtempstring* TempString) {
	TempString->NumOfChars = 0;
	TempString->c_str = malloc(sizeof(TempString) * 1);
	TempString->AllocMax = 1;
}

void LIGstrpush(ligtempstring* TempString, char Character) {
	if ((TempString->NumOfChars) >= TempString->AllocMax) {
			int AllocNeed = (TempString->NumOfChars << 1) + 1;
			TempString->AllocMax = AllocNeed;
			TempString->c_str = realloc(TempString, sizeof(TempString) * AllocNeed);
	}

	TempString->NumOfChars++;
	
	TempString->c_str[TempString->NumOfChars] = Character;
}

char* LIGstrreturn(ligtempstring* TempString) {
	char* ReturnValue = TempString->c_str;
	
	free(TempString->c_str);
	TempString->NumOfChars = 0;
	TempString->AllocMax = 1;
	
	return ReturnValue;
}

