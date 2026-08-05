#include <iostream>
#include <fstream>
#include <Light.hpp>

int main() {
	std::ofstream file("main.light");
	

	file << Light::OP_DEF_WRAPPER << Light::OP_STR_WRAP << "gcc" << Light::OP_STR_WRAP
		<< Light::OP_DEF << Light::OP_STR_WRAP << " mainfile.cpp" << Light::OP_STR_WRAP
		<< Light::OP_SET_SETTER << Light::SEC_0 << Light::SE_OUTPUT
		<< Light::OP_DEF << Light::OP_STR_WRAP << " mainfile" << Light::OP_STR_WRAP
		<< Light::OP_PUSH
		<< Light::OP_EXIT;
	return 0;
}
