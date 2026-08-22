#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <cstdio>
#include <cstdlib>
#include <light26.h>

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << "[Light] Need a valid file...\nTo get help do:\n lightinfo --help\n";
		return 1;
	}
	
	char* arg1 = argv[1];
	std::string argument1 = (std::string)arg1;

	std::filesystem::path myfile(argument1);

	std::ifstream thefile(argument1, std::ios::binary);

	uintmax_t charNum = 0;
	char* bytecode = nullptr;
	
	if (thefile.is_open()) {
		charNum = std::filesystem::file_size(myfile);
		bytecode = (char*) std::malloc(charNum * sizeof(char));
		thefile.read(&bytecode[0], charNum);
	}
	
	LightProcessor(bytecode, 0);

	std::free(bytecode);

	return 0;
}
