// 常量对象和常量成员函数
#include <iostream>

using namespace std;

class CSample
{
public:
	void PrintInfo() const;				// 声明常量成员函数
};
void CSample::PrintInfo() const			// 定义常量成员函数
{

}

int main()
{
	const CSample s;					// 定义常量对象
	s.PrintInfo();
	return 0;
}



// tips: 
//   1. 常量对象一旦初始化后，其值就不能再改变。
//   2. 常量成员函数内不允许出现可能修改非静态成员变量的语句，也不允许调用同类的其他非常量成员函数(静态成员函数除外)。
//   3. 如果两个成员函数的名字和参数表相同，但一个是 const 的，一个不是，则它们算重载。