#include <iostream>
#include <cstring>
#include "delivery_method.h"
#include "package.h"
#include "user.h"
#include "stock.h"

class Package;

Method::Method() {
		pkg = new Package;
		money = 0;
		danger = false;
}
	Method::Method(Package* x, double m, bool b) {
		pkg = x;
		money = m;
		danger = b;
}
	void Method::fee() {
		money = pkg->create_fee();
	}
	void Method::set_yndanger(bool flag) {
		danger = flag;
	}