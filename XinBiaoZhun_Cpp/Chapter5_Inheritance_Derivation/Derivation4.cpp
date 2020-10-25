#include <iostream>
#include <string>

using namespace std;

class A
{
private:
	int a;
public:
	A(int i) :a(i)
	{
		cout << "A " << a << " constructed" << endl;
	}
	~A()
	{
		cout << "A destructed" << endl;
	}
};
class B :public A
{
private:
	int b;
public:
	B(int i, int j) :A(i), b(j)
	{
		cout << "B " << b << " constructed" << endl;
	}
	~B()
	{
		cout << "B destructed" << endl;
	}
};
class C :public B
{
private:
	int c;
public:
	C(int i, int j, int k) : B(i, j), c(k)
	{
		cout << "C " << c << " constructed" << endl;
	}
	~C()
	{
		cout << "C destructed" << endl;
	}
};

int main()
{
	C obj(10, 11, 12);
	return 0;
}



// tips:
//   1. 在定义派生类时，只写直接基类，不写间接基类。派生类沿着类的层次自动向上继承它所有的间接基类。
//   2. 派生类的成员包括派生类自己定义的成员、直接基类中定义的成员，以及所有间接基类的全部成员。
//   3. 在派生类也是封闭类的情况下，派生类对象生成和消亡时，构造函数与析构函数的执行顺序是：
//	生成时，先从上至下执行所有基类的构造函数，再按照成员对象的定义顺序执行各个成员对象的构造函数，最后执行自身的构造函数；
//	消亡时，先执行自身的析构函数，然后按与构造的次序相反的顺序依次执行所有成员对象的析构函数，最后再从底向上依次执行各个基类的析构函数。
//	即，先构造的后析构。