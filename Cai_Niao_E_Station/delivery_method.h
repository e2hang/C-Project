#pragma once
#include <iostream>
#include "user.h"
#include "package.h"
#include "stock.h"

class Package;

class Method {
private:
	Package* pkg;
	double money;
	bool danger;
public:
	Method();
	Method(Package* x, double m, bool b);
	void fee();
	void set_yndanger(bool flag);

};