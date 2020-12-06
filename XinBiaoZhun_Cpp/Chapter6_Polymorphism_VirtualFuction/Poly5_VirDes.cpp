#include <iostream>

using namespace std;

class CShape
{
public:
	// 虚析构函数
	virtual ~CShape() { cout << "CShape::destructor" << endl; }

	/* 错误！不能将基类的析构函数声明为纯虚函数，链接时会报错。因为这样会导致，派生类对象消亡时，派生类的析构函数找不到基类的析构函数。
	virtual ~CShape() = 0;
	*/
};

class CRectangle :public CShape
{
public:
	// 虚析构函数
	virtual ~CRectangle() { cout << "CRectangle::destructor" << endl; }
};

int main()
{
	CShape* p = new CRectangle();
	delete p;						// 输出 CRectangle::destructor	CShape::destructor
	return 0;
}



// tips:
//	1. 虽然不能定义抽象类的对象，但是却可以定义抽象类的指针或引用。
//	2. 派生类的析构函数会自动调用基类的析构函数。
//	3. 只要基类的析构函数是虚函数，那么派生类的析构函数不论是否用virtual关键字声明，都自动成为虚析构函数。
//	4. 一般来说，一个类如果定义了虚函数，则最好将析构函数也定义为虚函数。
//	5. 析构函数可以是虚函数，但是构造函数不能是虚函数。