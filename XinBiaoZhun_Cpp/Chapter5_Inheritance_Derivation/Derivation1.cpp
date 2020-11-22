#include <iostream>
#include <string>

using namespace std;

class CStudent
{
private:
	string name;
	string id;
	char gender;
	int age;
public:
	void PrintInfo();
	void SetInfo(const string& name_, const string& id_, const char& gender_, const int& age_);
	string GetName();
};
class CUnderGraduateStudent :public CStudent
{
private:
	string department;
public:
	void QualifiedForBaoyan()
	{
		cout << "qualified for baoyan." << endl;
	}
	void PrintInfo()
	{
		CStudent::PrintInfo();
		cout << "Department:" << department << endl;
	}
	void SetInfo(const string& name_, const string& id_, const char& gender_, const int& age_, const string& department_)
	{
		CStudent::SetInfo(name_, id_, gender_, age_);
		department = department_;
	}
};
void CStudent::PrintInfo()
{
	cout << "Name:" << name << endl;
	cout << "ID:" << id << endl;
	cout << "Age:" << age << endl;
	cout << "Gender:" << gender << endl;
}
void CStudent::SetInfo(const string& name_, const string& id_, const char& gender_, const int& age_)
{
	name = name_;
	id = id_;
	gender = gender_;
	age = age_;
}
string CStudent::GetName()
{
	return name;
}

int main()
{
	CStudent s1;
	CUnderGraduateStudent s2;
	s2.SetInfo("Harry Potter", "20201025", 'M', 25, "Computer Science");	// 默认调用派生类中的 SetInfo
	cout << s2.GetName() << " ";
	s2.QualifiedForBaoyan();
	s2.PrintInfo();			// 默认调用派生类中的 PrintInfo
	cout << "sizeof(string)=" << sizeof(string) << endl;
	cout << "sizeof(CStudent)=" << sizeof(CStudent) << endl;
	cout << "sizeof(CUnderGraduateStudent)=" << sizeof(CUnderGraduateStudent) << endl;

	/* 可以这样来访问基类的同名成员 */
	CUnderGraduateStudent* ps = &s2;
	cout << s2.CStudent::GetName() << endl;
	ps->CStudent::PrintInfo();
	return 0;
}



// tips:
//   1. 派生类是通过对基类进行扩充和修改得到的。基类的所有成员自动成为派生类的成员。
//	所谓扩充，指的是在派生类中可以添加新的成员变量和成员函数；
//	所谓修改，指的是在派生类中可以重写从基类继承得到的成员。
//   2. 派生类的成员函数不能访问基类的私有成员。因为基类的私有成员成为了派生类的“不可访问”成员，只能通过基类的公有和保护方法访问。
//   3. 派生类对象占用的存储空间大小，等于基类对象占用的存储空间大小加上派生类对象新增成员变量占用的存储空间大小。
//	派生类对象中包含基类对象，而且基类对象的存储位置位于派生类对象新增的成员变量之前。
//   4. 在基类和派生类有同名成员时，可以是成员函数，也可以是成员变量，但是一般不会是同名成员变量，
//	在派生类的成员函数中访问同名成员,或通过派生类对象访问同名成员,除非特别指明,默认访问的就是派生类的成员,这种情况叫"覆盖"(override),即派生类的成员覆盖基类的同名成员。
//	可以像第71，72行那样来访问基类的同名成员。
//   5. 因为在不同的作用域中无法重载同名函数，所以声明在内层作用域的函数并不会重载声明在外层作用域的函数。因此，定义派生类中的函数也不会重载其基类中的成员。
//	和其他作用域一样，如果派生类(即内层作用域)的成员与基类(即外层作用域)的某个成员同名，则派生类将在其作用域内隐藏该基类成员。
//	即使派生类成员和基类成员的形参列表不一致，基类成员也仍然会被隐藏掉。