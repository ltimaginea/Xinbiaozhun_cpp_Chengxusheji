// 重载运算符 "[]"

#include <iostream>
#include <cstring>

using namespace std;

class CArray
{
private:
	int size;
	int* ptr;
public:
	CArray(int size_ = 0);
	CArray(const CArray& a);
	~CArray();
	int& operator[](int i);
	CArray& operator=(const CArray& a);
	void push_back(int v);
	int length() const;
};
CArray::CArray(int size_)
{
	if (size_ == 0)
	{
		size = 0;
		ptr = NULL;
	}
	else
	{
		size = size_;
		ptr = new int[size_];
	}
}
CArray::CArray(const CArray& a)		// 深拷贝
{
	if (a.ptr)
	{
		ptr = new int[a.size];
		memcpy(ptr, a.ptr, sizeof(int) * a.size);
		size = a.size;
	}
	else
	{
		size = 0;
		ptr = NULL;
	}
}
CArray::~CArray()
{
	if (ptr)
		delete[] ptr;
}
int& CArray::operator[](int i)
{
	return ptr[i];
}
CArray& CArray::operator=(const CArray& a)		// 深拷贝
{
	if (this == &a)			// 处理 a=a 这样的情况
		return *this;
	if (a.ptr)
	{
		if (size >= a.size)
		{
			memcpy(ptr, a.ptr, sizeof(int) * a.size);
			size = a.size;
		}
		else
		{
			if (ptr)
				delete[] ptr;
			ptr = new int[a.size];
			memcpy(ptr, a.ptr, sizeof(int) * a.size);
			size = a.size;
		}
	}
	/* 或者写成传统思路下面这样，但是上面程序的效率会更高些。
	if (ptr)
		delete[] ptr;
	if (a.ptr)
	{
		ptr = new int[a.size];
		memcpy(ptr, a.ptr, sizeof(int) * a.size);
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
void CArray::push_back(int v)
{
	if (ptr)
	{
		int* tmp = new int[size + 1];
		memcpy(tmp, ptr, sizeof(int) * size);
		tmp[size] = v;
		delete[] ptr;
		ptr = tmp;
		++size;
	}
	else
	{
		ptr = new int;
		ptr[0] = v;
		size = 1;
	}
}
int CArray::length() const
{
	return size;
}

int main()
{
	CArray a;
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
	CArray a2, a3;
	a2 = a;
	for (int i = 0; i < a2.length(); i++)
	{
		cout << a2[i] << " ";
	}
	a2 = a3;
	for (int i = 0; i < a2.length(); i++)
	{
		cout << a2[i] << " ";
	}
	cout << endl;
	a[3] = 100;
	CArray a4(a);
	for (int i = 0; i < a4.length(); i++)
	{
		cout << a4[i] << " ";
	}
	return 0;
}



// tips: 
//   1. C++规定，"[]" 只能重载为成员函数，不能重载为全局函数。
//   2. 按照 "[]" 原有特性， "a[i]" 应该能够作为左值使用，因此 operator[] 函数应该返回引用。
//   3. 这个程序演示了一个长度可变的整型数组类。