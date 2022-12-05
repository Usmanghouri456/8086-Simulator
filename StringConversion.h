#pragma once
#include <string>


std::string toStdString(System::String^ string)
{
	using System::Runtime::InteropServices::Marshal;
	System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	Marshal::FreeHGlobal(pointer);
	return returnString;
}


System::String^ toSystemString(std::string stdstring)
{
	System::String^ systemstring;
	systemstring = gcnew System::String(stdstring.c_str());
	return systemstring;
}
