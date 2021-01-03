// 类模板中的非类型参数

#include <iostream>

using namespace std;

template <typename T,int size>
class CArray
{
private:
	T my_array[size];
public:
	void print();
};

template <typename T, int size>
void CArray<T, size>::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << my_array[i] << endl;
	}
}

int main()
{
	CArray<int, 10> a1;			// 编译器生成名为 CArray<int, 10> 的类，该类是通过将 CArray 模板中的T换成int、size换成10后得到的。
	CArray<int, 30> a2;
	CArray<char, 30> a3;
	return 0;
}



// tips:
//	1. 类模板的“类型参数表”中可以出现非类型参数。
//	2. 注意， CArray<int, 10> 和 CArray<int, 30> 完全是两个不同的类，这两个类的对象之间不能互相赋值。