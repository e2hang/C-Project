#pragma once
#include <iostream>
#include "user.h"
#include "package.h"
#define USED0 0
#define ALL0 10
#define TOTAL0 100
#define STOCK_NUM 10
/*Ĭ�ϣ�
all(��������ܷż�������) =10
used = 0
���ڿ��������ļ��е���
*/

class Package;

class Stock {
private:
	int all;
	int used;
	std::string pid_code[ALL0];
public:
	Stock();
	Stock(int a, int l, int* p);
	Stock& inStock(Package& x);//x=pid
	//Stock& outStock(std::string x);//x=pid
	Stock& refresh();
	Stock& alert();
	int Check_used();
	std::string Check_Product(int n);
	std::string* Check_ProductAll();
	Stock& outStock(Package& x);
};