#include <stdio.h>

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

		if (ret != 0) {
			printf("{Light] POSIX EXECUTION FAILED;\n");
			return 1;
		}
#endif
	return 0;
}
