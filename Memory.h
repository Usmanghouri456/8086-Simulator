#pragma once
#include <fstream>
#include <string>
using std::string;
using std::fstream;
using std::ios;
using std::endl;



class Memory
{
private:
	fstream file;

public:
	Memory();
	string Read(string);
	void Write(string, string);
	bool fileExists();
	void createFile();
};





Memory::Memory() {
	if (!fileExists()) {
		createFile();
	}
}




bool Memory::fileExists() {
	file.open("Memory.txt", ios::in);
	if (file.is_open()) {
		file.close();
		return true;
	}
	file.close();
	return false;
}


void Memory::createFile() {
	file.open("Memory.txt", ios::out);
	if (file.is_open()) {
		for (int i = 0; i < 10; i++) {
			file << "0000" + std::to_string(i) << "H - 0000" << endl;
		}
		file << "0000AH - 0000" << endl;
		file << "0000BH - 0000" << endl;
		file << "0000CH - 0000" << endl;
		file << "0000DH - 0000" << endl;
		file << "0000EH - 0000" << endl;
		file << "0000FH - 0000" << endl;
		file.close();
	}
}


void Memory::Write(string address, string value) {
	string line;
	string data = "";

	while (value.length() < 4) {
		value = '0' + value;
	}

	file.open("Memory.txt", ios::in);
	if (file.is_open()) {
		while (getline(file, line))
		{
			if (line.substr(0, 5) == address) {
				data += address + "H - " + value + "\n";
			}
			else {
				data += line + "\n";
			}
		}
		file.close();
	}

	file.open("Memory.txt", ios::out);
	if (file.is_open()) {
		file << data;
		file.close();
	}
}


string Memory::Read(string address) {
	string line;
	file.open("Memory.txt", ios::in);
	if (file.is_open()) {
		while (getline(file, line))
		{
			if (line.substr(0, 5) == address) {
				file.close();
				return line.substr(9, line.length()-9);
			}
		}
		file.close();
	}
	return "";
}

