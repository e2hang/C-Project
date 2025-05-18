#include <iostream>
#include <cstring>
#include "stock.h"
#include "user.h"
#include "package.h"

class Package;


int min(int a, int b) {
	return a > b ? b : a;
}


Stock::Stock() {
	all = 10;
	used = 0;
	for (int i = 0;i < 10;i++) {
		pid_code[i] = "-1";
	}
}
Stock::Stock(int a, int l, int* p) {
	all = a;
	used = l;
	for (int i = 0;i < 10;i++) {
		pid_code[i] = *(p + i);
	}
}
int Stock::Check_used() {
	return used;
}
Stock& Stock::inStock(Package& x) {
	if (used != ALL0 && all - used > (int)(all * 0.2)) {
		int tmp = 0;
		for (int i = 0;i < ALL0;i++) {
			if (this->pid_code[i] == "-1") {
				tmp = i;
				break;
			}
		}
		pid_code[tmp] = x.Check_pid();
		x.alter_stock_num(tmp);
		x.alter_stockin(*this);
		used++;
		return *this;
	}
	else if (all - used <= (int)(all * 0.2)) {
		int tmp = 0;
		for (int i = 0;i < ALL0;i++) {
			if (this->pid_code[i] == "-1") {
				tmp = i;
				break;
			}
		}
		pid_code[tmp] = x.Check_pid();
		x.alter_stock_num(tmp);
		x.alter_stockin(*this);
		used++;
		this->alert();
		return *this;
	}
	else {
		cout << "This Stock is FULL. Search for Another One" << endl;
		return *this;
	}
	
}
Stock& Stock::outStock(Package& x) {
	//用包裹对象取货
	int s = x.Check_stock_num();
	if (s >= 0 && s <= ALL0) {
		pid_code[s] = "-1";
		this->refresh();
	}
	return *this;
}
//x=pid
Stock& Stock::refresh() {
	int cnt = 0;
	for (int i = 0;i < ALL0;i++) {
		if (pid_code[i] == "-1") {
			cnt++;
		}
	}
	cnt = used;
	return *this;
}
Stock& Stock::alert() {
	cout << "This Stock is ALMOST FULL." << endl;
	return *this;
}
std::string Stock::Check_Product(int n) {
	return pid_code[n-1];
}
std::string* Stock::Check_ProductAll() {
	return pid_code;
}
