#include <iostream>
#include <fstream>
#include <ligbus.hpp>

int main() {
	std::ofstream file("main.light");
	
	file
	<< (char)(0) << (char)(1)
	<< Light::OP_DEF << Light::OP_STR << "gcc" << Light::OP_STR
	<< Light::OP_DEF << Light::OP_STR << "program.c" << Light::OP_STR
	<< Light::OP_DEF << Light::OP_STR << "-o" << Light::OP_STR
	<< Light::OP_DEF << Light::OP_STR << "myprogram" << Light::OP_STR
	<< Light::OP_PUSH
	<< Light::OP_EXEC
	<< Light::OP_POP
	<< Light::OP_EXIT
	<< Light::OP_NULL << Light::OP_NULL << Light::OP_NULL << Light::OP_NULL;
	
	return 0;
}
