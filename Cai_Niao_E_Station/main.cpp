/*
Developed By


									   ...:::^^^^^^^^^:::..
									.::^^~~~~~~~~~~~~~~~~~^::..
								.:~?JYY?~^~^^^^^^^~~~~~~~~?YYJ?!:.
							   .:!7!!!7J5!^^^^^^^^^^^^~^!5Y7!!!7!^:.
							 .:^~~~~^^^^~7^^^^^^^^^^^^^^7!^~~~~~~~~:.
							.:~!!^::::::::^^::::::::^^^!!^::::^^^~~~^:.
						  .:::5GGY.        ..::::::^::YGG5.        .^^:.
						  .^:.7YY7:::::::....::..::^..!YY?^:^^:::....^~:.
						  :~~~^^^^~~^^^:::::......:::^:^^^~~~~~~~~~~~!~^.
						 .:~~~~~~~~~~^^:::........:::::^^^~~~~~~~~~~~!~^:
						 .^~~~~~~^^^^^^:::::::::::::::^^^^^~~~~~~~~~~!~^:
						 .^~~~~~~^^^^^^^::::::::::::^^^^^^^~~~~~~~~~~!~^:
						 .:~~~~~7!^^^^^^^^^^^:::^^^^^^^^^~~~~~~~7!~~!!~^.
						  .^~~~~!J!^^^^^^^^^^^^^^^^^^^^~~~~~~~~?J~~!!!~:.
						  .:^~~~~!Y?~^^~~^^^^^^^^^^^~~~~~~~~~7YJ!~!!!~^.
						   .:^~~~~~J5J7~~^^^^~~~~~~~~~~~~~!?YY?~~!!!~^.
							.:^~~~~~!?Y55J?7!!~~~~~~!77JY55Y7~~!!!~~:.
							  .:^~~~~~~!7JY555P5555P555Y?7!~~!!!!~^:.
								.:^~~!~~~~~~~!!!!!!!!~~~~~!!!!~~^:.
								  .::^~~!!!!!~~~~~~!!!!!!!!~~^:..
									 ..:^^~~~~~~!!!~~~~~^^::..
	                                     ....:::::::::...                    

*/






#include <iostream>
#include <cstring>
#include <stdexcept>
#include "package.h"
#include "user.h"
#include "stock.h"
#include "delivery_method.h"
#include "exception.h"
#define Endl std::endl 
//Exception E;

Package* k;
User* p;

std::string Crypt(std::string x, std::string y);

using std::cin;
using std::cout;
using std::endl;
using std::string;

extern Stock cainiao[10];
extern User temp;
extern void PRINT_LIU_YING();

int main() {
	//先print一下，哈哈
	//PRINT_LIU_YING();
	//初始化人员列表
	p = new User[20];
	p[1].reg("Zhang", "111111198301", "000011");
	p[2].reg("Wang", "12211198301", "000012");
	p[3].reg("Li", "13311198301", "000013");
	p[4].reg("Zhao", "14411198301", "000014");
	p[5].reg("Sun", "15511198301", "000015");
	p[6].reg("Zhou", "16611198301", "000016");
	p[7].reg("Xu", "17711198301", "000017");
	p[8].reg("Wan", "18811198301", "000018");
	p[9].reg("Liu", "19911198301", "000019");
	p[10].reg("Su", "10011198301", "000020");
	p[11].reg("Green", "10111198301", "000021");

	//测试：检测手机号是否为11位功能

	/*旧版
	try {
		std::string test01, test02, test03;
		test01 = "ERROR";
		test02 = "98301";
		test03 = "000022";
		p[12].reg(test01, test02, test03);
		if (test02.size() != 11) {
			throw E.User_Phone_Number_Error();
			delete &p[12];
		}
	}
	catch (const std::string& x) {
		cout << x << endl;
	}*/
	//新版
	try {
		std::string test01, test02, test03;
		test01 = "ERROR";
		test02 = "98301";
		test03 = "000022";
		p[12].reg(test01, test02, test03);
		if (test02.size() != 11) {
			throw Etest::User_Phone_Number_Error();
			delete& p[12];
		}
	}
	catch (const std::runtime_error& x) {
		cout << x.what() << endl;
	}


	k = new Package[TOTAL0];
	k[1] = Package("Dildo", "pid1919810", "2025-05-08-00-00-00", "2025-05-09-10-00-00", &temp, 5.4, 10.0, 10.3, false);
	k[2] = Package("Clothes", "10002", "2025-05-06-14-15-00", "2025-05-08-11-30-00", &p[2], 1.5, 8.0, 5.6, false);
	k[3] = Package("Laptop", "10003", "2025-05-05-10-00-00", "2025-05-06-09-20-00", &p[3], 3.0, 15.0, 20.2, false);
	k[4] = Package("Shoes", "10004", "2025-05-07-16-00-00", "2025-05-09-08-00-00", &p[4], 2.8, 9.5, 6.1, false);
	k[5] = Package("Snacks", "10005", "2025-05-08-09-45-00", "2025-05-09-14-00-00", &p[5], 1.2, 5.0, 3.7, false);
	k[6] = Package("Monitor", "10006", "2025-05-06-11-20-00", "2025-05-07-10-10-00", &p[6], 6.5, 20.0, 18.9, false);
	k[7] = Package("Tablet", "10007", "2025-05-07-13-50-00", "2025-05-08-17-00-00", &p[3], 1.8, 14.0, 10.5, false);
	k[8] = Package("Camera", "10008", "2025-05-05-07-30-00", "2025-05-06-08-00-00", &p[3], 2.6, 11.0, 9.2, false);
	k[9] = Package("Glasses", "10009", "2025-05-06-12-00-00", "2025-05-07-15-30-00", &p[9], 0.8, 4.0, 2.0, false);
	k[10] = Package("Headphones", "10010", "2025-05-08-10-00-00", "2025-05-09-13-00-00", &p[10], 1.1, 6.0, 4.4, false);
	k[11] = Package("Books", "10011", "2025-05-07-08-30-00", "2025-05-08-10-00-00", &p[1], 2.3, 12.5, 8.0, false);
	//测试用户系统
	cout << "Display User :" << endl;
	temp.display();
	p[2].display();
	cout << "Alter p2" << Endl;
	p[2].alt_name("W..");
	p[2].alt_pn("110");
	p[2].display();
	cout << "测试结束" << endl;
	cout << endl;

	//测试包裹存储驿站、超额警报
	cout << "检测： Stock k1 ~ k11 to Stock0, Stock1" << Endl;
	cainiao[0].inStock(k[1]);
	cainiao[0].inStock(k[2]);
	cainiao[0].inStock(k[3]);
	cainiao[0].inStock(k[4]);
	cainiao[0].inStock(k[5]);
	cainiao[0].inStock(k[6]);
	cainiao[0].inStock(k[7]);
	cainiao[0].inStock(k[8]);
	cainiao[0].inStock(k[9]);
	cainiao[1].inStock(k[10]);
	cainiao[1].inStock(k[11]);


	cout << "已存入" << Endl;
	cout << "展示库存：DisPlay Stock" << Endl;
	for (int i = 0;i < 10;i++) {
		cout << *(cainiao[0].Check_ProductAll() + i) << " ";
	}
	cout << Endl;
	for (int i = 0;i < 10;i++) {
		cout << *(cainiao[1].Check_ProductAll() + i) << " ";
	}
	cout << endl;
	cout << "测试结束" << endl;

	//测试取出包裹的对应
	//k1.display();
	cout << "测试取出包裹的对应" << Endl;
	k[1].create_vc();
	string Code = Crypt(temp.Check_uid(), k[1].Check_pid());
	k[1].verifing(Code, "2025-05-10-10-00-00");
	k[1].display();
	cout << endl;
	cout << "展示库存变化" << Endl;
	for (int i = 0;i < 10;i++) {
		cout << *(cainiao[0].Check_ProductAll() + i) << " ";
	}
	cout << Endl;
	for (int i = 0;i < 10;i++) {
		cout << *(cainiao[1].Check_ProductAll() + i) << " ";
	}
	cout << Endl;

	//向空Stock加入包裹（从小往上加）
	cout << "测试向空Stock加入包裹（从小往上加）" << endl;
	cainiao[0].inStock(k[1]);
	for (int i = 0;i < 10;i++) {
		cout << *(cainiao[0].Check_ProductAll() + i) << " ";
	}
	cout << Endl;
	for (int i = 0;i < 10;i++) {
		cout << *(cainiao[1].Check_ProductAll() + i) << " ";
	}
	cout << "测试结束" << endl;
	cout << Endl;
	
	//查询用户的包裹
	cout << "测试查询用户包裹" << Endl;
	int dw = 3;
	cout << "	先展示用户信息" << endl;
	p[dw].display();
	cout << "再展示货物信息" << Endl;
	k[3].display();
	cout << "下面开始查询" << Endl;
	Package* pkgs = p[dw].Check_Package();
	for (int i = 0;i < TOTAL0 - 1;i++){
		if(pkgs[i].Check_pid() != "#UNDEFINED_P:P" ) 
			cout << pkgs[i].Check_pid() << " ";

	}
	cout << Endl;

	//查询包裹状态，拥有者
	k[2].display();


	//测试付费系统


	cout << "Test Over" << endl;
	return 0;
}