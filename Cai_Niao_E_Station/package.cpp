#include <iostream>
#include <cstring>
#include "package.h"
#include "user.h"

extern std::string Crypt(std::string x,std::string y){
	std::string temp;
	temp = x;
	int t;
	t = (int)y[0];
	t /= 5;
	for (int i = 0;i < x.size();i++) {
		temp[i] += t;
	}
	return temp;
}

Package::Package() {
	name = "#UNDEFINED_N:P";
	pid = "#UNDEFINED_P:P";
	owner = new User;
	jichu_time = "#UNDEINFED_JT:P";
	songda_time = "#UNDEINFED_SD:P";
	quhuo_time = "#UNDEFINED_QH:P";
	is_picked = false;
	volume = -1;
	mass = -1;
	distance = -1;
	stockin = NULL;
	stock_num = 0;
	is_vfast = false;
}
Package::Package(std::string n, std::string pi, std::string j, std::string s, User* o, double v, double m, double d,bool v0) {
	//owner = new User;
	name = n;
	pid = pi;
	owner = o;
	jichu_time = j;
	songda_time = s;
	quhuo_time = "#REQUIRD";
	is_picked = false;
	volume = v;
	distance = d;
	mass = m;
	is_vfast = v0;
	stockin = NULL;
	stock_num = 0;
}
//有Bug懒得改了，尽量不用，用Stock里面的inStock
Package& Package::stocked(Stock* x) {
	stockin = x;
	stock_num = x->Check_used();
	x->inStock(*this);
	if (pid == x->Check_Product(x->Check_used())) {
		cout << "Successfully Stocked" << endl;
	}
	else {
		cout << "Stock Error! Please Try Again" << endl;
	}
	return *this;
}

void Package::create_vc() {
	verify_code = Crypt(owner->Check_uid(), pid);
	cout << "Verify Code Created" << endl;
}
void Package::verifing(std::string n,std::string time) {
	if (verify_code == n) {
		quhuo_time = time;
		is_picked = true;
		stockin->outStock(*this);
		return;
	}
	else {
		cout << "Verify Code WRONG!" << endl;
		return;
	}
	if (stockin->Check_Product(stock_num) == "-1") {
		cout << "Successfully Picked!" << endl;
	}
	else {
		cout << "Can't Be Selected" << endl;
	}
}
Package& Package::alter_stock_num(int n) {
	stock_num = n;
	return *this;
}
Package& Package::alter_stockin(Stock& x) {
	stockin = &x;
	return *this;
}

std::string Package::Check_pid() {
	return pid;
}
std::string Package::Check_vc() {
	return verify_code;
}
int Package::Check_stock_num() {
	return stock_num;
}
User* Package::Check_User() {
	return owner;
}
double Package::create_fee() {
	double fee;
	if (!is_vfast)	fee = 5 * mass + 0.5 * volume;
	if (is_vfast)	fee = 1.3 * (5 * mass + 0.5 * volume);
	return fee;
}
Package& Package::operator=(const Package& x) {
	name = x.name;
	pid = x.pid;
	owner = x.owner;
	jichu_time = x.jichu_time;
	songda_time = x.songda_time;
	quhuo_time = x.quhuo_time;
	is_picked = x.is_picked;
	verify_code = x.verify_code;
	volume = x.volume;
	mass = x.mass;
	distance = x.distance;
	is_vfast = x.is_vfast;
	stockin = x.stockin;
	stock_num = x.stock_num;
	return *this;
}

void Package::display() {
	cout << "Package Name : " << name << endl;
	cout << "Package Pid : " << pid << endl;
	cout << "Package Owner : (Displayed Down)" << endl;
	owner->display();
	cout << "Package jichu_time : " << jichu_time << endl;
	cout << "Package songda_time : " << songda_time << endl;
	cout << "Package quhuo_time : " << quhuo_time << endl;
	cout << "Package Picked? : " << is_picked << endl;
	cout << "Package Mass : " << mass << endl;
	cout << "Package Volume : " << volume << endl;
	cout << "Package Distance : " << distance << endl;
}


