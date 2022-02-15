#include <fcntl.h>
#include <io.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
	//Set Console mode
	_setmode(_fileno(stdout), _O_U8TEXT);
	
	std::wstring input;

	std::wstring str;
	std::wstringstream ss;


	//Testing for a string and stringstream
	str = L"â à ä ç é è ê ë î ï ô ù û ü";
	ss << str << L" and " << str;


	//Write to File
	std::wofstream outFile("accentedChar.txt");
	if (outFile.is_open()) {

		outFile << "Writing string: " << str << std::endl;
		outFile << "Writing stringstream: " << ss.rdbuf() << std::endl;
	}
	else {
		std::wcout << L"Could not open file";
	}
	
	//Read from file to validate integrity
	std::wifstream ResultReader("accentedChar.txt", std::ios::binary | std::ios::ate);
	if (ResultReader.is_open()) {
		auto FileSize = ResultReader.tellg();
		ResultReader.seekg(std::ios::beg);
		std::wstring Results(FileSize, 0);
		ResultReader.read(&Results[0], FileSize);
		std::wcout << Results;
	}
	else {
		std::wcout << L"Could not find file." << std::endl;
	}
		



	return 0;
}
