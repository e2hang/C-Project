#include <iostream>
#include "exception.h"

using std::cout;
using std::endl;

/*
std::string Exception::User_Phone_Number_Error() {
	return "电话号码不是11位数字，请重新输入！";
}
std::string Exception::Package_Time_Format_Error() {
	return "输入时间格式不正确！请按照2025-05-10-10-05-00的格式输入！";
}
std::string Exception::Stock_Used_More_Than_All_Error() {
	return "货架可存储量大于使用量！请检查输入是否正确！";
}
*/
std::runtime_error Etest::User_Phone_Number_Error() {
	return std::runtime_error("电话号码不是11位数字，请重新输入！");
}

std::runtime_error Etest::Package_Time_Format_Error()
{
	return std::runtime_error("输入时间格式不正确！请按照2025-05-10-10-05-00的格式输入！");
}

std::runtime_error Etest::Stock_Used_More_Than_All_Error()
{
	return std::runtime_error("货架可存储量大于使用量！请检查输入是否正确！");
}
