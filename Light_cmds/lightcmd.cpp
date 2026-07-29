#include <iostream>
#include <vector>
#include <string>

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << "[Light] Need a valid file...\nTo get help do:\n lightinfo --help\n";
		return 1;
	}
	
	std::vector<std::string> arguments;

	for (int i = 0; i < argc; i++) {
		arguments.push_back(argv[i]);
	}

	for (int i = 0; i < argc; i++) {
		std::cout << "file interpret thing\n";
	}

	return 0;
}
