#include <fcntl.h>
#include <io.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
	_setmode(_fileno(stdout), _O_U8TEXT);
	
	std::string input;

	std::string str;
	std::stringstream ss;



	str = "â à ä ç é è ê ë î ï ô ù û ü œ";
	ss << str << "and" << str;


	
		std::ofstream outFile("accentedChar.txt");

		if (outFile.is_open()) {

			outFile << "Writing string: " << str << std::endl;
			outFile << "Writing stringstream: " << ss.rdbuf() << std::endl;
		}
		else {
			std::wcout << "Could not open file";
		}
	

	
		std::ifstream inFile("accentedChar.txt");

		if (inFile.is_open()) {

			while (getline(inFile, input)) {

				std::cout << input << std::endl;
			}
		}
		else {
			std::cout << "Could not open file";
		}
	




	return 0;
}
