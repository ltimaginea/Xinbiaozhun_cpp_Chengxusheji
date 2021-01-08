// 类模板中的static成员

#include <iostream>

using namespace std;

template <typename T>
class A
{
private:
	static int count;
public:
	static void PrintCount();
	A() { count++; }
	A(A& a) { *this = a; count++; }
	~A() { count--; }
};

// 与普通类的static数据成员相同，模板类的每个static数据成员必须在定义类的文件中对其进行一次声明或初始化
template<typename T>
int A<T>::count = 0;		// 定义并初始化

template <typename T>
void A<T>::PrintCount()
{
	cout << count << endl;
}

int main()
{
	A<int> ia;
	A<double> da1;
	A<double>* da2 = nullptr;
	da2 = new A<double>;
	ia.PrintCount();
	A<double>::PrintCount();
	delete da2;
	A<double>::PrintCount();
	return 0;
}



// tips:
//	1. 类模板中可以定义静态成员，从该类模板实例化得到的所有类都包含同样的静态成员。
//	示例中，类 A<double> 的两个对象 da1 和 da2 共享相同的 A<double>::count 和 A<double>::PrintCount() 成员，但显然它们和类 A<int> 的对象 ia 不会共享一份count和PrintCount() 。
//	2. 与普通类的static数据成员相同，模板类的每个static数据成员必须有且仅有一个定义。
//	3. 类似任何其他成员函数，一个static成员函数只有在使用时才会实例化。