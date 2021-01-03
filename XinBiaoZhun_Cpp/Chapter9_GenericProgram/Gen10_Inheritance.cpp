// 类模板与继承

#include <iostream>

using namespace std;

// 类模板从类模板继承
template <typename T1,typename T2>
class ABase
{
public:
	T1 abase1;
	T2 abase2;
	ABase(T1 abase1_, T2 abase2_) :abase1(abase1_), abase2(abase2_) {}
};
template <typename T1,typename T2>
class A :public ABase<T2, T1>
{
public:
	T1 a1;
	T2 a2;
	A(T1 abase1_, T2 abase2_) :ABase<T2, T1>(abase2_, abase1_) {}
};



// 类模板从模板类继承
template <typename T>
class BBase
{
private:
	T bbase;
};
template <typename T1,typename T2>
class B :public BBase<char>
{
private:
	T1 b1;
	T2 b2;
};



// 类模板从普通类继承
class CBase
{
private:
	double cbase;
};
template <typename T1,typename T2>
class C :public CBase
{
private:
	T1 c1;
	T2 c2;
};



// 普通类从模板类继承
template <typename T1,typename T2>
class DBase
{
private:
	T1 dbase1;
	T2 dbase2;
};
class D :public DBase<char, double>
{
private:
	int d;
};



int main()
{
	A<double, char> a(5.5, '3');
	B<int, double> b;
	C<char, int> c;
	D d;
	printf("%X %lf\n", a.abase1, a.abase2);			// 输出 33 5.500000
	return 0;
}



// tips:
//	1. 类模板和类模板之间、类模板和类之间可以互相继承。它们之间的继承关系有以上四种情况。