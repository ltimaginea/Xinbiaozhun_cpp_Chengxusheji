#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class CShape
{
public:
	virtual double Area() = 0;
	virtual void PrintInfo() = 0;
	// 虚析构函数
	virtual ~CShape() {}

	/* 错误！不能将基类的析构函数声明为纯虚函数，链接时会报错。因为这样会导致，派生类对象消亡时，派生类的析构函数找不到基类的析构函数。
	virtual ~CShape() = 0;
	*/
};

class CRectangle :public CShape
{
public:
	int w, h;
	virtual double Area();
	virtual void PrintInfo();
	virtual ~CRectangle() {}
};

class CCircle :public CShape
{
public:
	int r;
	virtual double Area();
	virtual void PrintInfo();
	virtual ~CCircle() {}
};

class CTriangle :public CShape
{
public:
	int a, b, c;
	virtual double Area();
	virtual void PrintInfo();
	virtual ~CTriangle() {}
};

double CRectangle::Area()
{
	return w * h;
}

void CRectangle::PrintInfo()
{
	cout << "Rectangle's area = " << Area() << endl;
}

double CCircle::Area()
{
	return r * r * 3.14;
}

void CCircle::PrintInfo()
{
	cout << "Circle's area = " << Area() << endl;
}

double CTriangle::Area()
{
	// 根据海伦公式计算三角形面积
	double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void CTriangle::PrintInfo()
{
	cout << "Triangle's area = " << Area() << endl;
}

CShape* pShapes[100];

int MyCompare(const void* s1, const void* s2)
{
	CShape** p1 = (CShape**)s1;
	CShape** p2 = (CShape**)s2;
	double a1 = (*p1)->Area();
	double a2 = (*p2)->Area();
	if (a1 < a2)
		return -1;
	else if (a2 < a1)
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	CRectangle* pr;
	CCircle* pc;
	CTriangle* pt;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		switch (c)
		{
		case 'R':
		{
			pr = new CRectangle();
			cin >> pr->w >> pr->h;
			pShapes[i] = pr;
			break;
		}
		case 'C':
		{
			pc = new CCircle();
			cin >> pc->r;
			pShapes[i] = pc;
			break;
		}
		case 'T':
		{
			pt = new CTriangle();
			cin >> pt->a >> pt->b >> pt->c;
			pShapes[i] = pt;
			break;
		}
		}

	}
	qsort(pShapes, n, sizeof(CShape*), MyCompare);
	for (int i = 0; i < n; i++)
	{
		pShapes[i]->PrintInfo();
		delete pShapes[i];
	}
	return 0;
}



// tips:
//	1. 虽然不能定义抽象类的对象，但是却可以定义抽象类的指针。
