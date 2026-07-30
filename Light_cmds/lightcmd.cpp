#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Light.hpp>

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << "[Light] Need a valid file...\nTo get help do:\n lightinfo --help\n";
		return 1;
	}
	
	char* arg1 = argv[1];
	std::string argument1 = (std::string)arg1;

	std::ifstream thefile(argument1);
	
	char getChar;
	Light::Bytecode bytecode;

	while (getChar = thefile.get()) {
		bytecode.push_back(getChar);
	}

	Light::interpret(bytecode);

	return 0;
}
