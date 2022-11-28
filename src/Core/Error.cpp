#include <cstdlib>
#include <iostream>
#include <string>

void FatalError(std::string output)
{
	std::cout << output << std::endl;
	exit(EXIT_FAILURE);
}
