#include <iostream>

using namespace std;

class CWolf;
class CGhost;
class CThunderBird;

class CCreature
{
protected:
	int lifeValue;
	int power;
public:
	void Attack(CCreature* p) {}
	void Hurted(int nPower) {}
	void FightBack(CCreature* p) {}
};

class CDragon :public CCreature
{
public:
	void Attack(CDragon* p);
	void Attack(CWolf* p);
	void Attack(CGhost* p);
	void Attack(CThunderBird* p);
	void Hurted(int nPower);
	void FightBack(CDragon* p);
	void FightBack(CWolf* p);
	void FightBack(CGhost* p);
	void FightBack(CThunderBird* p);
};

class CWolf :public CCreature
{
public:
	void Attack(CDragon* p);
	void Attack(CWolf* p);
	void Attack(CGhost* p);
	void Attack(CThunderBird* p);
	void Hurted(int nPower);
	void FightBack(CDragon* p);
	void FightBack(CWolf* p);
	void FightBack(CGhost* p);
	void FightBack(CThunderBird* p);
};

class CGhost :public CCreature
{
public:
	void Attack(CDragon* p);
	void Attack(CWolf* p);
	void Attack(CGhost* p);
	void Attack(CThunderBird* p);
	void Hurted(int nPower);
	void FightBack(CDragon* p);
	void FightBack(CWolf* p);
	void FightBack(CGhost* p);
	void FightBack(CThunderBird* p);
};

class CThunderBird :public CCreature
{
public:
	void Attack(CDragon* p);
	void Attack(CWolf* p);
	void Attack(CGhost* p);
	void Attack(CThunderBird* p);
	void Hurted(int nPower);
	void FightBack(CDragon* p);
	void FightBack(CWolf* p);
	void FightBack(CGhost* p);
	void FightBack(CThunderBird* p);
};

void CDragon::Attack(CDragon* p)
{
	p->Hurted(power);
	p->FightBack(this);
}
void CDragon::Attack(CWolf* p)
{
	p->Hurted(power);
	p->FightBack(this);
}
void CDragon::Attack(CGhost* p)
{
	p->Hurted(power);
	p->FightBack(this);
}
void CDragon::Attack(CThunderBird* p)
{
	p->Hurted(power);
	p->FightBack(this);
}

void CDragon::Hurted(int nPower)
{
	lifeValue -= nPower;
}

void CDragon::FightBack(CDragon* p)
{
	p->Hurted(power / 2);			// 这里是通过其他对象的成员函数来访问其他对象的保护成员
	
	/* 正确。下面这样来使攻击者的生命值减少也可以。在类的成员函数内部，既能够访问当前对象的全部属性、函数，也可以访问同类其他对象的全部属性、函数。
	p->lifeValue -= power / 2;
	*/
}
void CDragon::FightBack(CWolf* p)
{
	p->Hurted(power / 2);			// 这里是通过其他对象的成员函数来访问其他对象的保护成员

	/* 错误。不能像下面这样来使攻击者的生命值减少。因为,一个类的保护成员只能在其成员函数或其派生类的成员函数中被访问。
	p->lifeValue -= power / 2;
	*/
}
void CDragon::FightBack(CGhost* p)
{
	p->Hurted(power / 2);			// 这里是通过其他对象的成员函数来访问其他对象的保护成员

	/* 错误。不能像下面这样来使攻击者的生命值减少。因为,一个类的保护成员只能在其成员函数或其派生类的成员函数中被访问。
	p->lifeValue -= power / 2;
	*/
}
void CDragon::FightBack(CThunderBird* p)
{
	p->Hurted(power / 2);			// 这里是通过其他对象的成员函数来访问其他对象的保护成员

	/* 错误。不能像下面这样来使攻击者的生命值减少。因为,一个类的保护成员只能在其成员函数或其派生类的成员函数中被访问。
	p->lifeValue -= power / 2;
	*/
}


void CWolf::Attack(CDragon* p) { p->Hurted(power); p->FightBack(this); }
void CWolf::Attack(CWolf* p) { p->Hurted(power); p->FightBack(this); }
void CWolf::Attack(CGhost* p) { p->Hurted(power); p->FightBack(this); }
void CWolf::Attack(CThunderBird* p) { p->Hurted(power); p->FightBack(this); }
void CWolf::Hurted(int nPower) { lifeValue -= nPower; }
void CWolf::FightBack(CDragon* p) { p->Hurted(power / 2); }
void CWolf::FightBack(CWolf* p) { p->Hurted(power / 2); }
void CWolf::FightBack(CGhost* p) { p->Hurted(power / 2); }
void CWolf::FightBack(CThunderBird* p) { p->Hurted(power / 2); }

void CGhost::Attack(CDragon* p) { p->Hurted(power); p->FightBack(this); }
void CGhost::Attack(CWolf* p) { p->Hurted(power); p->FightBack(this); }
void CGhost::Attack(CGhost* p) { p->Hurted(power); p->FightBack(this); }
void CGhost::Attack(CThunderBird* p) { p->Hurted(power); p->FightBack(this); }
void CGhost::Hurted(int nPower) { lifeValue -= nPower; }
void CGhost::FightBack(CDragon* p) { p->Hurted(power / 2); }
void CGhost::FightBack(CWolf* p) { p->Hurted(power / 2); }
void CGhost::FightBack(CGhost* p) { p->Hurted(power / 2); }
void CGhost::FightBack(CThunderBird* p) { p->Hurted(power / 2); }

void CThunderBird::Attack(CDragon* p) { p->Hurted(power); p->FightBack(this); }
void CThunderBird::Attack(CWolf* p) { p->Hurted(power); p->FightBack(this); }
void CThunderBird::Attack(CGhost* p) { p->Hurted(power); p->FightBack(this); }
void CThunderBird::Attack(CThunderBird* p) { p->Hurted(power); p->FightBack(this); }
void CThunderBird::Hurted(int nPower) { lifeValue -= nPower; }
void CThunderBird::FightBack(CDragon* p) { p->Hurted(power / 2); }
void CThunderBird::FightBack(CWolf* p) { p->Hurted(power / 2); }
void CThunderBird::FightBack(CGhost* p) { p->Hurted(power / 2); }
void CThunderBird::FightBack(CThunderBird* p) { p->Hurted(power / 2); }

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
//	1. 可以看到，非多态的实现，代码庞大，而且不易于维护，如当增加新的怪物“骑士”时，除了要编写一个“骑士”类，所有的类中还都需要增加对应的Attack,FightBack成员函数。
