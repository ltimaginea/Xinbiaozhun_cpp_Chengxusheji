// 运算符重载 += == > < ()
#include <iostream>
#include <cstring>
#include <cstdlib>
#pragma warning(disable:4996)

using namespace std;

class CMyString
{
private:
	char* ptr;
	int size;
public:
	CMyString();
	CMyString(const char* c);
	CMyString(const CMyString& str);
	~CMyString();
	void duplicate(const CMyString& str);
	CMyString& operator=(const char* c);
	CMyString& operator=(const CMyString& str);
	bool operator==(const CMyString& str) const;
	bool operator>(const CMyString& str) const;
	bool operator<(const CMyString& str) const;
	CMyString operator+(const CMyString& str);
	CMyString& operator+=(const CMyString& str);
	char& operator[](int i) const;
	CMyString operator()(int start, int len) const;
	friend ostream& operator<<(ostream& os, const CMyString& str);
};
CMyString::CMyString()
{
	ptr = new char[2];
	ptr[0] = 0;
	size = 0;
}
CMyString::CMyString(const char* c)
{
	if (c)
	{
		int len = strlen(c);
		ptr = new char[len + 1];
		strcpy(ptr, c);
		size = len;
	}
	else
	{
		ptr = new char[2];
		ptr[0] = 0;
		size = 0;
	}
}
void CMyString::duplicate(const CMyString& str)
{
	if (str.size > size)
	{
		if (ptr)
			delete[] ptr;
		ptr = new char[str.size + 1];
	}
	strcpy(ptr, str.ptr);
	size = str.size;
}
CMyString::CMyString(const CMyString& str) :ptr(new char[1]), size(0)
{
	duplicate(str);
}
CMyString::~CMyString()
{
	if (ptr)
		delete[] ptr;
}
CMyString& CMyString::operator=(const char* c)
{
	if (strlen(c) > size)
	{
		if (ptr)
			delete[] ptr;
		ptr = new char[strlen(c) + 1];
	}
	strcpy(ptr, c);
	size = strlen(c);
	return *this;
}
CMyString& CMyString::operator=(const CMyString& str)
{
	if (this == &str)
		return *this;
	duplicate(str);
	return *this;
}
bool CMyString::operator==(const CMyString& str) const
{
	return strcmp(ptr, str.ptr) == 0;
}
bool CMyString::operator>(const CMyString& str) const
{
	return strcmp(ptr, str.ptr) > 0;
}
bool CMyString::operator<(const CMyString& str) const
{
	return strcmp(ptr, str.ptr) < 0;
}
CMyString CMyString::operator+(const CMyString& str)
{
	char* tmp = new char[size + str.size + 2];
	strcpy(tmp, ptr);
	strcat(tmp, str.ptr);
	CMyString os(tmp);
	delete[] tmp;
	return os;
}
CMyString& CMyString::operator+=(const CMyString& str)
{
	char* tmp = new char[size + str.size + 2];
	strcpy(tmp, ptr);
	strcat(tmp, str.ptr);
	/*size = size + str.size;
	delete[] ptr;
	ptr = tmp;*/
	CMyString os(tmp);
	delete[] tmp;
	*this = os;
	return *this;
}
char& CMyString::operator[](int i) const
{
	return ptr[i];
}
CMyString CMyString::operator()(int start, int len) const
{
	char* tmp = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		tmp[i] = ptr[start + i];
	}
	tmp[len] = 0;
	CMyString os(tmp);
	delete[] tmp;
	return os;
}
ostream& operator<<(ostream& os, const CMyString& str)
{
	os << str.ptr;
	return os;
}
CMyString operator+(const char* c, const CMyString& str)
{
	CMyString tmp(c);
	tmp += str;
	return tmp;
}

int CompareString(const void* e1, const void* e2)
{
	CMyString* s1 = (CMyString*)e1;
	CMyString* s2 = (CMyString*)e2;
	if (*s1 < *s2) return -1;
	else if (*s1 > * s2) return 1;
	else return 0;
}

int main()
{
	CMyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	CMyString SArray[4] = { "big","me","about","take" };
	cout << "1." << s1 << s2 << s3 << s4 << endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2." << s1 << endl;
	cout << "3." << s2 << endl;
	cout << "4." << s3 << endl;
	cout << "5." << s4 << endl;
	cout << "6." << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7." << s2 << endl;
	cout << "8." << s1 << endl;
	s1 += "mnop";
	cout << "9." << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10." << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11." << s1 << endl;
	qsort(SArray, 4, sizeof(CMyString), CompareString);
	for (int i = 0; i < 4; i++)
	{
		cout << SArray[i] << endl;
	}
	cout << s1(0, 4) << endl;
	cout << s1(5, 10) << endl;
	return 0;
}