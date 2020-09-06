// 封闭类 (enclosed class)

#include <iostream>

using namespace std;

class CTyre
{
private:
	int radius;
	int width;
public:
	CTyre(int tr, int tw) :radius(tr), width(tw) {}
};
class CEngine
{

};
class CCar						// 封闭类
{
private:
	int price;
	CTyre tyre;					// 成员对象
	CEngine engine;					// 成员对象
public:
	CCar(int p, int tr, int tw) :price(p), tyre(tr, tw) {}
};

int main()
{
	CCar car(2700, 12, 23);
	return 0;
}


// tips: 
//   1. 封闭类，可以在构造函数中借助初始化列表进行初始化成员对象，来使编译器能够弄明白其成员对象是如何初始化的。
//   2. 封闭类对象生成时，先执行所有成员对象的构造函数，然后才执行封闭类自己的构造函数。
//      成员对象构造函数的执行次序和成员对象在类中定义的次序一致，与它们在构造函数初始化列表中出现的次序无关。
//   3. 封闭类对象消亡时，先执行封闭类的析构函数，然后再执行成员对象的析构函数，成员对象析构函数的执行次序和构造函数的执行次序相反。
//   4. 简而言之，先构造的后析构。
//   5. 封闭类的对象生成时，要先执行成员对象的构造函数，是因为封闭类的构造函数中可能用到成员对象。如果此时成员对象还没有初始化，那就不合理了。
//   6. 封闭类的对象消亡时，要先执行封闭类的析构函数，然后才执行成员对象的析构函数，也是因为封闭类的析构函数中可能用到成员对象。
//      如果此时成员对象已经被析构，那么此时封闭类的析构函数访问成员对象的数据就可能会产生错误。