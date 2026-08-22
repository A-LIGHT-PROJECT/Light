#include <iostream>
#include <fstream>

int main() {
	std::ofstream file("main.light");
	
	file
	<< (char)(1) << "gcc myprogram.c -o myprogram" << (char)(0) << (char)(0);
	
	return 0;
}
