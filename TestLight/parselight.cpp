#include <iostream>
#include <fstream>
#include <ligbus.hpp>

int main() {
	std::ofstream file("main.light");
	
	file << Light::OP_DEF << Light::OP_STR << "gcc program.c -o thisprogram" << Light::OP_STR
	<< Light::OP_PUSH
	<< Light::OP_EXEC
	<< Light::OP_POP
	<< Light::OP_EXIT;
	
	return 0;
}
