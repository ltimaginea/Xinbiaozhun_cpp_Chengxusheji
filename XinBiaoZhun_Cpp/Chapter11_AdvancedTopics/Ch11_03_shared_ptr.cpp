#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	int i_;
	A(int i) :i_(i) {}
	~A()
	{
		cout << i_ << " destructor" << endl;
	}
};

int main()
{
	shared_ptr<A> sp1(new A(2));
	shared_ptr<A> sp2(sp1);
	shared_ptr<A> sp3;
	sp3 = sp1;
	cout << sp1->i_ << "," << sp2->i_ << "," << sp3->i_ << endl;
	A* p = sp3.get();
	cout << p->i_ << endl;
	sp1.reset(new A(3));
	sp2.reset(new A(4));
	cout << sp1->i_ << endl;
	sp3.reset(new A(5));
	cout << "end" << endl;

	return 0;
}

// tips:
//	1. 不要将同一块内存绑定到多个独立创建的shared_ptr上，否则会触发运行时错误："double freed or corruption"。unique_ptr同是。