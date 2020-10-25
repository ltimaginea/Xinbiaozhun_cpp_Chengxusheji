#include <iostream>
#include <string>

using namespace std;

class CBug
{
private:
	int legNum;
	int color;
public:
	CBug(int ln, int cl) :legNum(ln), color(cl)
	{
		cout << "CBug Constructor" << endl;
	}
	~CBug()
	{
		cout << "CBug Destructor" << endl;
	}
	void PrintInfo()
	{
		cout << legNum << "," << color << endl;
	}
};
class CFlyingBug :public CBug
{
private:
	int wingNum;
public:
	//CFlyingBug() {}		// 错误！会导致CBug类使用无参构造函数进行初始化，但是CBug类没有无参构造函数
	CFlyingBug(int ln, int cl, int wn) :CBug(ln, cl), wingNum(wn)
	{
		cout << "CFlyingBug Constructor" << endl;
	}
	~CFlyingBug()
	{
		cout << "CFlyingBug Destructor" << endl;
	}
};

int main()
{
	CFlyingBug fb(57, 89, 5);
	fb.PrintInfo();
	return 0;
}



// tips:
//   1. 和封闭类说明成员对象如何初始化类似，派生类说明基类对象如何初始化，也需要在构造函数后面添加初始化列表。
//   2. 当派生类对象生成时，先执行基类的构造函数，后执行自身的构造函数；消亡时，先执行自身的析构函数，再执行基类的析构函数。
//	即“先构造的后析构”。
//   3. 和封闭类的情况类似，如果一个派生类是用默认复制构造函数初始化的，那么它内部包含的基类对象也要用基类的复制构造函数初始化。