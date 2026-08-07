#include <iostream>

#include <cstdlib>
#include <cstring>
#include <string>
#include <lightexe.hpp>

int spawnexe(const char* argv[]) {
#if IS_WINDOWS
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	
	std::string cpparg;

	for (int i = 0; i < (sizeof(argv) / sizeof(argv[0])); i++) {
		cpparg += argv[i];
	}
	const char* arg = cpparg.c_str();

	wchar_t wtext[cpparg.size() * 2];

	mstowcs(wtext, arg, std::strlen(arg) + 1);

	LPWSTR command = wtext;

	if (!CreateProcessW(nullptr, command, nullptr, nullptr, 0, CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi)) {
		std::cerr << "WINDOWS API CREATEPROCESS FAILED;\n";
		return 1;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
#else
	const char* PATHNAME = std::filesystem::absolute(std::filesystem::path(argv[0])).c_str();
	int childpid;
	if ((childpid = fork()) == -1) {
		perror("FORK FAILED;\n");
		exit(1);
	} else if (childpid == 0) {
		execvp(PATHNAME, argv);
		exit(0);
	} else {
		exit(0);
	}
	return childpid == -1;
#endif
}
