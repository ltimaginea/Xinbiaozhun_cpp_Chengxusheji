#include <iostream>
#include <string>

using namespace std;

template <typename T1,typename T2>
class Pair
{
public:
	T1 key;
	T2 value;
	Pair(T1 k, T2 v) :key(k), value(v) {}
	bool operator<(const Pair& p) const;
};

template <typename T1,typename T2>
bool Pair<T1, T2>::operator<(const Pair& p) const
{
	return key < p.key;
}

int main()
{
	Pair<string, int> student("Tom", 19);
	cout << student.key << " " << student.value << endl;
	
	Pair<string, int> student2("Jack", 29);
	if (student < student2)
		cout << "operator< is called!" << endl;
	else
		cout << "operator< is called aslo!" << endl;
	return 0;
}



// tips:
//	1. 类模板(class template)是用来生成类的蓝图的。与函数模板的不同之处是，编译器不能为类模板推断模板参数类型。
//	为了使用类模板，我们必须在模板名后的尖括号中提供显式模板实参，用来一一对应地替换模板列表中的类型参数。
//	2. 编译器由类模板生成类的过程叫类模板的实例化。由类模板实例化得到的类叫模板类。
//	3. 默认情况下，对于一个实例化了的类模板，其成员只有在使用时才被实例化。如果一个成员函数没有被使用，则它不会被实例化。
//	成员函数只有在被用到时才进行实例化，这一特性使得即使某种类型不能完全符合模板操作的要求，我们仍然能用该类型实例化类。