#include <iostream>
#include "exception.h"

using std::cout;
using std::endl;

/*
std::string Exception::User_Phone_Number_Error() {
	return "�绰���벻��11λ���֣����������룡";
}
std::string Exception::Package_Time_Format_Error() {
	return "����ʱ���ʽ����ȷ���밴��2025-05-10-10-05-00�ĸ�ʽ���룡";
}
std::string Exception::Stock_Used_More_Than_All_Error() {
	return "���ܿɴ洢������ʹ���������������Ƿ���ȷ��";
}
*/
std::runtime_error Etest::User_Phone_Number_Error() {
	return std::runtime_error("�绰���벻��11λ���֣����������룡");
}

std::runtime_error Etest::Package_Time_Format_Error()
{
	return std::runtime_error("����ʱ���ʽ����ȷ���밴��2025-05-10-10-05-00�ĸ�ʽ���룡");
}

std::runtime_error Etest::Stock_Used_More_Than_All_Error()
{
	return std::runtime_error("���ܿɴ洢������ʹ���������������Ƿ���ȷ��");
}
