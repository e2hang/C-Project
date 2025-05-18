#pragma once
#include <iostream>
#include <cstring>
#include <stdexcept>
/*
class Exception {
public:
	std::string User_Phone_Number_Error();
	std::string Package_Time_Format_Error();
	std::string Stock_Used_More_Than_All_Error();



};*/

class Etest : public std::runtime_error{
public:
	static std::runtime_error User_Phone_Number_Error();
	static std::runtime_error Package_Time_Format_Error();
	static std::runtime_error Stock_Used_More_Than_All_Error();
};