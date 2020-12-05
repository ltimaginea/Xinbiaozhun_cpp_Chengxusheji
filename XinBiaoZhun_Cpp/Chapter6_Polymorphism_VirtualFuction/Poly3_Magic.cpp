#include <iostream>

using namespace std;

class CCreature
{
protected:
	int lifeValue;
	int power;
public:
	// 纯虚函数
	virtual void Attack(CCreature* p) = 0;
	virtual void Hurted(int nPower) = 0;
	virtual void FightBack(CCreature* p) = 0;
};

class CDragon :public CCreature
{
public:
	// C++11 override 关键字
	virtual void Attack(CCreature* p) override;
	virtual void Hurted(int nPower) override;
	virtual void FightBack(CCreature* p) override;
};

class CWolf :public CCreature
{
	virtual void Attack(CCreature* p) override;
	virtual void Hurted(int nPower) override;
	virtual void FightBack(CCreature* p) override;
};

class CGhost :public CCreature
{
	virtual void Attack(CCreature* p) override;
	virtual void Hurted(int nPower) override;
	virtual void FightBack(CCreature* p) override;
};

class CThunderBird :public CCreature
{
	virtual void Attack(CCreature* p) override;
	virtual void Hurted(int nPower) override;
	virtual void FightBack(CCreature* p) override;
};

void CDragon::Attack(CCreature* p)
{
	p->Hurted(power);
	p->FightBack(this);
}

void CDragon::Hurted(int nPower)
{
	lifeValue -= nPower;
}

void CDragon::FightBack(CCreature* p)
{
	p->Hurted(power / 2);

	/* 不能像下面这样来使攻击者的生命值减少。
	因为,派生类的成员函数只能间接访问所作用的那个对象(即this指针指向的对象)的基类保护成员，不能访问其他基类对象的基类保护成员。
	p->lifeValue -= power / 2;
	*/
}

void CWolf::Attack(CCreature* p) { p->Hurted(power); p->FightBack(this); }
void CWolf::Hurted(int nPower) { lifeValue -= nPower; }
void CWolf::FightBack(CCreature* p) { p->Hurted(power / 2); }

void CGhost::Attack(CCreature* p) { p->Hurted(power); p->FightBack(this); }
void CGhost::Hurted(int nPower) { lifeValue -= nPower; }
void CGhost::FightBack(CCreature* p) { p->Hurted(power / 2); }

void CThunderBird::Attack(CCreature* p) { p->Hurted(power); p->FightBack(this); }
void CThunderBird::Hurted(int nPower) { lifeValue -= nPower; }
void CThunderBird::FightBack(CCreature* p) { p->Hurted(power / 2); }

int main()
{
	CDragon dragon;
	CWolf wolf;
	CGhost ghost;
	CThunderBird bird;
	dragon.Attack(&wolf);
	dragon.Attack(&ghost);
	dragon.Attack(&bird);
	return 0;
}



// tips:
//	1. 可以看到，CCreature 类的不同派生类的成员函数的内部实现都是一样的，只是实际游戏中的实现动作和声音的代码会不同而已。
//	2. “纯虚函数”的写法就是在函数声明后面加 "=0" ，不写函数体。包含“纯虚函数”的类称为“抽象类”，抽象类不能生成独立的对象。
//	“抽象类”的派生类，仅当实现了所有的纯虚函数，才会变成非抽象类。
//	3. 可以使用 "override" 关键字来标记派生类中的虚函数，如果该虚函数并没有覆盖基类中的虚函数(如因为同名但形参表不一致)，编译器将报错。
//	4. 可以通过单步调试，来观察运行时的多态。