class CBase
{
private:
	int nPrivate;				// 私有成员
public:
	int nPublic;				// 公有成员
protected:
	int nProtected;				// 保护成员
};
class CDerived :public CBase
{
	void AccessBase(CDerived& cd)
	{
		nPublic = 1;			// OK
		//nPrivate = 1;			// 错，不能访问基类私有成员
		nProtected = 1;			// OK，访问从基类继承的 protected 成员
		CBase f;
		//f.nProtected = 1;		// 错，f 不是函数所作用的对象
		cd.nProtected = 1;
	}
};

int main()
{
	CBase b;
	CDerived d;
	//int n = b.nProtected;			// 错，在类的成员函数外部，不能访问基类保护成员
	//n = d.nPrivate;			// 错，此处不能访问d的私有成员
	d.nPublic = 10;				// OK
	return 0;
}



// tips:
//   1. private : 用来指定私有成员。一个类的私有成员，不论是成员变量还是成员函数，都只能在本类的成员函数内部才能被访问。
//   	因此，在类的成员函数内部，既能够访问当前对象的全部属性、函数，也可以访问同类其他对象的全部属性、函数。
//   2. public : 用来指定公有成员。一个类的公有成员在任何地方都可以被访问。
//   3. protected : 用来指定保护成员。保护成员的可访问范围比私有成员大，比公有成员小。能访问私有成员的地方都能访问保护成员。
//   	保护成员扩大的范围表现在：基类的保护成员可以在派生类的成员函数中被访问。
//   	不过需要注意的是，派生类的成员函数只能间接访问所作用的那个对象(即this指针指向的对象)的基类保护成员，不能访问其他基类对象的基类保护成员。