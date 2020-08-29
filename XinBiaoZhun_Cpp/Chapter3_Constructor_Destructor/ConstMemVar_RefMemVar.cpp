// const 成员和引用成员

#include <iostream>

using namespace std;

int f;
class CDemo
{
private:
	const int num;				// 常量型成员变量
	int& ref;				// 引用型成员变量
	int value;
public:
	CDemo(int n) :num(n), ref(f), value(3) {}
};

int main()
{
	cout << sizeof(CDemo) << endl;		// 输出 12
	return 0;
}

// tips: 
//   1. 类中的常量型成员变量和引用型成员变量，必须在构造函数的初始化列表中进行初始化。
//   2. 常量型成员变量的值一旦被初始化，就不能再改变。