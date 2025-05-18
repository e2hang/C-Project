#pragma once
#include <iostream>
#include <cstring>
#include "package.h"
#include "stock.h"

class Package;

class User {

private:
	std::string name;
	std::string phone_num;
	//�����Ȳ�ʹ�ã��������ֱ��ͳ�ư���//��Package��
	std::string uid;//�ⲿ�洢user������user��uid���ֵ
	int jingyan;
public:
	User();
	User(std::string n, std::string p, std::string u);
	~User();
	User& reg(std::string n, std::string p, std::string u);
	User& alt_name(std::string n);
	User& alt_pn(std::string p);
	void del();
	std::string Check_uid();
	void display();
	std::string Check_name();
	std::string Check_phone();
	User& add_exp(int s);
	User& refresh();
	Package* Check_Package();
	User& operator=(const User& x);
	bool operator==(const User& x);
};

class VIP : public User {
private:
	//std::string name;
	//std::string phone_num;
	//std::string uid;
	//int jingyan;
	bool flag;
public:
	VIP();
	VIP(User& x, bool f);
	VIP& reg(User& x);
};