#pragma once
#include <string>
using std::string;



class Register
{
public:
	string data;


	Register();
	void setData(string);
	void setLowerByte(string);
	void setHigherByte(string);

	string getData();
	string getLowerByte();
	string getHigherByte();
};





Register::Register() {
	data = "0000";
}


void Register::setData(string value) {
	while (value.length() < 4) {
		value = '0' + value;
	}
	data = value;
}


void Register::setLowerByte(string value) {
	if (value.length() < 2) {
		value = '0' + value;
	}
	data.replace(2, 2, value);
}


void Register::setHigherByte(string value) {
	if (value.length() < 2) {
		value = '0' + value;
	}
	data.replace(0, 2, value);
}



string Register::getData() {
	return data;
}


string Register::getLowerByte() {
	return data.substr(2, 2);
}


string Register::getHigherByte() {
	return data.substr(0, 2);
}