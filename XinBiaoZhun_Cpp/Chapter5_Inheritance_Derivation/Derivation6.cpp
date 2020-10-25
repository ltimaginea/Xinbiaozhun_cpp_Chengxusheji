#include <iostream>
#include <string>

using namespace std;

class CBase
{
//protected:
private:
	int n;
public:
	CBase(int i) :n(i) {}
	void Print()
	{
		cout << "CBase:n=" << n << endl;
	}
};
class CDerived :public CBase
{
public:
	int v;
	CDerived(int i) :CBase(i), v(2 * i) {}
	void Print()
	{
		//cout << "CDerived::n=" << n << endl;
		CBase::Print();
		cout << "CDerived::v=" << v << endl;
	}
	void Func() {}
};

int main()
{
	CDerived objDerived(3);
	CBase objBase(5);
	CBase* pBase = &objDerived;
	//pBase->Func();						// 错，CBase 类没有Func()成员函数
	//pBase->v = 5;							// 错，CBase 类没有v成员变量
	pBase->Print();
	cout << "1)----------------------" << endl;
	//CDerived* pDerived = &objBase;		// 错，不能将基类地址赋值给派生类指针
	CDerived* pDerived = (CDerived*)&objBase;
	pDerived->Print();						// 慎用，可能出现不可预期的错误
	cout << "2)----------------------" << endl;
	objDerived.Print();
	cout << "3)----------------------" << endl;
	pDerived->v = 128;						// 往其他对象的空间中写入数据会有问题
	objDerived.Print();
	return 0;
}



// tips:
//	1. 在公有派生的情况下，派生类的指针可以直接赋值给基类指针。但即便基类指针指向的是一个派生类的对象，也不能通过基类指针访问基类没有而派生类中有的成员。
//	2. 基类的指针不能赋值给派生类的指针。但是通过强制类型转换，也可以将基类指针强制转换成派生类指针后再赋值给派生类指针。
//		在这种情况下，需要保证被转换的基类指针本来就指向一个派生类的对象，这样才是安全的，否则很容易出错。
//	3. 将基类指针强制转换为派生类指针，或将基类引用强制转换为派生类引用，都存在安全隐患。