#pragma once
#include <iostream>
#include <cstring>
#include "user.h"
#include "stock.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class User;
class Stock;

class Package {
private:
	std::string name;
	std::string pid;//auto
	User* owner;
	std::string jichu_time;
	std::string songda_time;//time format: 2025-05-08-23-15-03(eazy to cmp and check)
	std::string quhuo_time;
	bool is_picked;
	std::string verify_code;
	double volume;
	double mass;
	double distance;
	bool is_vfast;
	Stock* stockin;
	int stock_num;
public:
	Package();
	Package(std::string n, std::string pid, std::string j, std::string s, User* o,double v , double m, double d,bool v0);
	void create_vc();
	void verifing(std::string n, std::string time);
	std::string Check_pid();
	std::string Check_vc();
	double create_fee();
	int Check_stock_num();
	void display();
	Package& stocked(Stock* x);
	Package& alter_stock_num(int n);
	Package& alter_stockin(Stock& x);
	User* Check_User();
	Package& operator=(const Package& x);
};