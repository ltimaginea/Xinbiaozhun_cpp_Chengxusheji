#include <iostream>

using namespace std;

class CBase
{
public:
	int i;
	void func1() {}
};

class CDerived :public CBase
{
public:
	virtual void func2() {}
};

class CDerived2 :public CDerived
{
	void func3() {}
};

int main()
{
	// 输出(32位程序指针为4字节) 4,8,8 或 (64位程序指针为8字节) 4,16,16 (也可能是其他，有对齐问题，示例64位程序中，CDerived类其成员类型的最大值为指针8字节，则以8字节对齐，所以输出 4,16,16)
	cout << sizeof(CBase) << "," << sizeof(CDerived) << "," << sizeof(CDerived2) << endl;
	return 0;
}



// tips:
//	1. 可以发现，有了虚函数以后，对象所占用的存储空间比没有虚函数时多了4个字节。这4个字节就是实现多态的关键——它位于对象存储空间的最前端，其中存放的是虚函数表的地址。
//	2. 每一个有虚函数的类（或有虚函数的类的派生类）都有一个虚函数表，该类的任何对象中都放着该虚函数表的指针（可以认为这是由编译器自动添加到构造函数中的指令完成的）。
//	虚函数表是编译器生成的，程序运行时被载入内存。一个类的虚函数表中列出了该类的全部虚函数地址。