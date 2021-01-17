// 类模板实例：可变长数组类模板

#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class CArray
{
private:
	int size;
	T* ptr;
public:
	CArray(int size_ = 0);				// 通过指定size_默认值，使其同时发挥无参构造函数的作用
	CArray(const CArray& a);
	~CArray();
	void push_back(T v);
	int length() const;
	T& operator[](int i);
	/*
		在类代码内可以简化模板类名的使用。当我们使用一个类模板类型时必须提供模板实参，但这一规则有一个例外。在类模板自己的作用域中，我们可以直接使用模板名而不提供实参。
		因此在类模板内声明成员 运算符函数operator= 时，它的返回值类型和形参类型可以简写为 CArray& 。
	*/
	CArray& operator=(const CArray& a);
};

template <typename T>
CArray<T>::CArray(int size_)
{
	if (size_ == 0)
	{
		size = 0;
		ptr = NULL;
	}
	else
	{
		size = size_;
		ptr = new T[size_];
	}
}

template <typename T>
CArray<T>::CArray(const CArray& a)		// 深拷贝
{
	if (a.ptr)
	{
		ptr = new T[a.size];
		memcpy(ptr, a.ptr, sizeof(T) * a.size);
		size = a.size;
	}
	else
	{
		size = 0;
		ptr = NULL;
	}
}

template <typename T>
CArray<T>::~CArray()
{
	if (ptr)
		delete[] ptr;
}

template <typename T>
T& CArray<T>::operator[](int i)
{
	return ptr[i];
}

/*
	我们在类模板外定义成员 operator= 时，必须记住，我们并不在类的作用域中，直到遇到类名才表示进入类的作用域。
	由于返回类型位于类的作用域之外，我们必须指出返回类型是一个实例化的CArray，它所用类型与类实例化所用类型一致。
	遇到类名时表示进入类的作用域，在类模板自己的作用域中，我们可以直接使用模板名而不提供实参，编译器将假定我们使用的类型与类实例化所用类型一致。
	因此 运算符函数operator= 的形参 a 定义等价于 const CArray<T>& a 。
*/
template <typename T>
CArray<T>& CArray<T>::operator=(const CArray& a)		// 深拷贝
{
	if (this == &a)			// 处理 a=a 这样的情况
		return *this;
	if (a.ptr)
	{
		if (size >= a.size)
		{
			memcpy(ptr, a.ptr, sizeof(T) * a.size);
			size = a.size;
		}
		else
		{
			if (ptr)
				delete[] ptr;
			ptr = new T[a.size];
			memcpy(ptr, a.ptr, sizeof(T) * a.size);
			size = a.size;
		}
	}
	/* 或者写成传统思路下面这样，但是上面程序的效率会更高些。
	if (ptr)
		delete[] ptr;
	if (a.ptr)
	{
		ptr = new T[a.size];
		memcpy(ptr, a.ptr, sizeof(T) * a.size);
		size = a.size;
	}
	*/
	else
	{
		if (ptr)
			delete[] ptr;
		ptr = NULL;
		size = 0;
	}
	return *this;
}

template <typename T>
void CArray<T>::push_back(T v)
{
	if (ptr)
	{
		T* tmp = new T[size + 1];
		memcpy(tmp, ptr, sizeof(T) * size);
		tmp[size] = v;
		delete[] ptr;
		ptr = tmp;
		++size;
	}
	else
	{
		ptr = new T;
		ptr[0] = v;
		size = 1;
	}
}

template <typename T>
int CArray<T>::length() const
{
	return size;
}

int main()
{
	CArray<short> a;
	for (int i = 0; i < 5; i++)
	{
		a.push_back(i);
	}
	a = a;
	for (int i = 0; i < a.length(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	CArray<double> a2, a3;
	for (int i = 0; i < 7; i++)
	{
		a2.push_back(i * 3.7);
	}
	a3 = a2;
	for (int i = 0; i < a3.length(); i++)
	{
		cout << a3[i] << " ";
	}
	cout << endl;
	a[3] = 100;
	CArray<short> a4(a);
	for (int i = 0; i < a4.length(); i++)
	{
		cout << a4[i] << " ";
	}
	return 0;
}



// tips: 
//	1. 在类代码内可以简化模板类名的使用。当我们使用一个类模板类型时必须提供模板实参，但这一规则有一个例外。在类模板自己的作用域中，我们可以直接使用模板名而不提供实参。
//	我们在类模板外定义成员 operator= 时，必须记住，我们并不在类的作用域中，直到遇到类名才表示进入类的作用域。
//	由于返回类型位于类的作用域之外，我们必须指出返回类型是一个实例化的CArray，它所用类型与类实例化所用类型一致。
//	遇到类名时表示进入类的作用域，在类模板自己的作用域中，我们可以直接使用模板名而不提供实参，编译器将假定我们使用的类型与类实例化所用类型一致。
//	2. C++规定，"[]" 只能重载为成员函数，不能重载为全局函数。
//	3. 按照 "[]" 原有特性， "a[i]" 应该能够作为左值使用，因此 operator[] 函数应该返回引用。
//	4. 这个程序演示了一个可变长数组类模板。