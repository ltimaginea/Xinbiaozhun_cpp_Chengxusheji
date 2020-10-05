// 重载赋值运算符 "="

#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

class CString
{
private:
	char* str;
public:
	CString() :str(NULL) {}
	CString(const char* s);
	CString(const CString& s);
	const char* c_str() const;
	CString& operator=(const char* s);
	CString& operator=(const CString& s);
	~CString();
};
CString::CString(const char* s)				// 类型转换构造函数，使得 CString s2 = "hello!"; 能够成立
{
	/* 这是为了应对这样的情况：CString s = "hello!"; s = "Shenzhou 8!"; 这时便需要释放先前分配的动态内存。
	   但是因为"="已经有被重载 CString& operator=(const char* s); ，这样的情况并不会触发这个类型转换构造函数，所以可以注释掉这里。
	if (str)
		delete[] str;
	*/
	if (s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	else
		str = NULL;
}
CString::CString(const CString& s)			// 深拷贝
{
	if (s.str)
	{
		str = new char[strlen(s.str) + 1];
		strcpy(str, s.str);
	}
	else
		str = NULL;
}
const char* CString::c_str() const
{
	return str;
}
CString& CString::operator=(const char* s)		// 重载 "="，使得 obj="Good Luck," 能够成立
{
	if (str)
		delete[] str;
	if (s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	else
		str = NULL;
	return *this;
}
CString& CString::operator=(const CString& s)		// 深拷贝
{
	if (this == &s)			// 为了应对 s=s 这样的情况
		return *this;
	if (str)
		delete[] str;
	if (s.str)
	{
		str = new char[strlen(s.str) + 1];
		strcpy(str, s.str);
	}
	else
		str = NULL;
	return *this;
}
CString::~CString()
{
	if (str)
		delete[] str;
}

int main()
{
	CString s;
	s = "Good Luck,";				// 等价于 s.operator=("Good Luck,");
	cout << s.c_str() << endl;
	CString s2 = "hello!";
	cout << s2.c_str() << endl;
	s = "Shenzhou 8!";				// 等价于 s.operator=("Shenzhou 8!");
	cout << s.c_str() << endl;

	CString& ss = s;
	CString& sss = s;
	sss = ss;					// 第66，67行，s=s 的情况

	CString s11, s12;
	s11 = "this";
	s12 = "that";
	s12 = s11;			// 深拷贝

	CString s21;
	s21 = "Transformers";
	CString s22(s2);		// 深拷贝
	return 0;
}



// tips: 
//   1. C++规定，"=" 只能重载为成员函数。
//   2. 没有经过重载，"=" 的作用就是把左边的变量变得和右边的相等，即执行逐个字节拷贝的工作，对于指针变量，会使得两个指针指向同一个地方，这样的拷贝就叫做“浅拷贝”。
//   3. 将一个指针变量指向的内容复制到另一个指针变量指向的地方，这样的拷贝就叫做“深拷贝”。
//   4. 第66，67行是为了应付这样的情况：s=s;