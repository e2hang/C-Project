#include <iostream>
#include <cstring>
#include "package.h"
#include "user.h"
#include "stock.h"

class Package;
class Stock;

extern Stock cainiao[STOCK_NUM];
extern Package* k;

	//Package package_num();//用Package类

	User::User() {
		name = "#UNDEFINED_N";
		phone_num = "#UNDEFINED_P";
		uid = "#UNDEFINED_U";
		jingyan = -1;
	}
	User::User(std::string n, std::string p, std::string u) {
		name = n;
		phone_num = p;
		uid = u;
		jingyan = 0;
	}
	

	User& User::reg(std::string n, std::string p, std::string u) {
		name = n;
		phone_num = p;
		uid = u;
		jingyan = 0;
		if (p.size() == 11)	cout << n + ", Your are registered!" << endl;
		else
		{
			cout << "Hello " + n + " ";
		}
		return *this;
	}
	User& User::alt_name(string n) {
		name = n;
		cout << "Name altered to " + n << endl;
		return *this;
	}
	User& User::alt_pn(string p) {
		phone_num = p;
		cout << "Phone Number altered to " + p << endl;
		return *this;
	}
	void User::del() {
		name = "#DELETED_" + name;
		phone_num = "#DELETED_" + phone_num;
		uid = "#DELETED_" + uid;
		cout << "User Deleted" << endl;
	}
	void User::display() {
		cout << "	Name :" + name << endl;
		cout << "	Phone Number: " + phone_num << endl;
		cout << "	uid :" + uid << endl;
	}
	std::string User::Check_uid() {
		return uid;
	}
	std::string User::Check_name() {
		return name;
	}

	std::string User::Check_phone() {
		return phone_num;
	}
	User& User::operator=(const User& x) {
		name = x.name;
		phone_num = x.phone_num;
		uid = x.uid;
		jingyan = x.jingyan;
		return *this;
	}
	bool User::operator==(const User& x) {
		if (name == x.name &&
			phone_num == x.phone_num &&
			uid == x.uid &&
			jingyan == x.jingyan
			)
			return true;
		else
			return false;
	}
	Package* User::Check_Package() {
		Package *tp = new Package [TOTAL0];
		int cnt = 0;
		cout << "Chekcing Packages" << endl;
		for (int i = 0;i < TOTAL0; i++) {
			//extern k[i]的问题，查询系统是正确的
				if (*(k[i].Check_User()) == *this) {
					tp[cnt] = k[i];
					//cout << "YES" << endl;
					cnt++;
				}
		}
		if (cnt == 0) {
			cout << "没有查询到包裹" << endl;
		}
		return tp;
	}

	User& User::add_exp(int s) {
		jingyan += s;
		return *this;
	}
	User& User::refresh() {
		if (jingyan >= 100) {
			VIP* temp = new VIP;
			temp->reg(*this);
			return *temp;
		}
		return *this;
	}


	VIP::VIP() {
		flag = true;
}

VIP::VIP(User& x,bool f) : User(x.Check_name(), x.Check_phone(),x.Check_uid()) {
	flag = f;
}

VIP& VIP::reg(User& x){
	flag = true;
	return *this;
}
User::~User() {
	//delete[] temp;
}