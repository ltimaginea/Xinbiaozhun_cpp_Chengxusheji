// 常量对象和常量成员函数
#include <iostream>

using namespace std;

class CSample
{
private:
	int n;
public:
	CSample();
	void PrintInfo() const;					// 声明常量成员函数
	void PrintInfo();					// 重载 PrintInfo
};
CSample::CSample() :n(1) {}
void CSample::PrintInfo() const					// 定义常量成员函数
{
	cout << n << endl;
}
void CSample::PrintInfo()
{
	n = n * 2;
	cout << n << endl;
}

int main()
{
	const CSample s1;					// 定义常量对象
	CSample s2;
	s1.PrintInfo();						// 只能调用 PrintInfo() const
	s2.PrintInfo();						// 调用 PrintInfo()，即会优先调用 PrintInfo()
	return 0;
}



// tips: 
//   1. 如果两个成员函数的名字和参数表相同，但一个是 const 的，一个不是，则它们算重载。
//   2. 常量对象一旦初始化后，其值就不能再改变。
//   3. 常量成员函数内不允许出现可能修改非静态成员变量的语句，也不允许调用同类的其他非常量成员函数(静态成员函数除外)。