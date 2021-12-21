#include <iostream>

using namespace std;

class CRectangle
{
private:
	int w;
	int h;
	static int totalArea;
	static int totalNumber;
public:
	CRectangle(int w_, int h_);
	CRectangle(const CRectangle& r);
	~CRectangle();
	static void PrintTotal();
};
CRectangle::CRectangle(int w_, int h_)
{
	w = w_;
	h = h_;
	totalNumber += 1;
	totalArea += w * h;
}
CRectangle::CRectangle(const CRectangle& r)
{
	w = r.w;
	h = r.h;
	totalNumber += 1;
	totalArea += r.w * r.h;
}
CRectangle::~CRectangle()
{
	totalNumber -= 1;
	totalArea -= w * h;
}
void CRectangle::PrintTotal()
{
	cout << totalNumber << "," << totalArea << endl;
}

// 必须在定义类的文件中对静态成员变量进行一次声明或初始化，
// 否则编译能通过，但是链接(link)不能通过，链接阶段会报告“标识符找不到”。
int CRectangle::totalNumber = 0;
int CRectangle::totalArea = 0;

int main()
{
	CRectangle r1(2, 5);
	CRectangle r2(r1);
	CRectangle::PrintTotal();
	r1.PrintTotal();				// 等效于 CRectangle::PrintTotal();
	r2.PrintTotal();				// 等效于 CRectangle::PrintTotal();
	// cout << CRectangle::totalNumber;		// 错误，totalNumber 是私有的
	return 0;
}



// tips: 
//   1. 静态成员变量只有一份，被所有同类对象共享，本质上是全局变量。
//   2. 静态成员函数并不具体作用在某个对象上，本质上是全局函数。
//   3. 因为静态成员函数不具体作用于某个对象，所以静态成员函数内部不能访问非静态成员变量，也不能调用非静态成员函数。
//   4. sizeof()运算符计算对象所占的存储空间时，不会将静态成员变量计算在内。sizeof(CRectangle)的值是8。
//   5. 示例中重写复制构造函数是为了保证每一个矩形对象生成时，总数和总面积都能够被及时准确增加。