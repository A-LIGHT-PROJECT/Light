#include <iostream>
#include <Light.hpp>

int main(int argc, char** argv) 
{
	if (argc == 1) {
		std::cout << "LIGBUS 1, get started with: lightinfo --help\n";
		return 0;
	}
	
	std::vector<std::string> arguments;

	for (int i = 0; i < argc; i++) {
		std::string thisstring = argv[i];
		arguments.push_back(thisstring);
	}

	if (arguments.at(1) == "--help") {
		std::cout << "HELP MENU: \n"
			<< "lightinfo --help: Gives you this help menu...\n"
			<< "lightinfo --version: Gives the version of LIGBUS (Light Builds)\n"
			<< "lightinfo --gettext <bytecode file>: Disassembles light bytecode files into text you can read\n"
			<< "light <bytecode file>: Executes that bytecode through the Light Builds Virtual Machine\n";
		return 0;
	}

	if (arguments.at(1) == "--version") {
		std::cout << "LIGBUS 1\n";
		return 0;
	}

	return 0;
}
