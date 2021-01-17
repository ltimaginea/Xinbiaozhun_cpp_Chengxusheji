// 类模板和友元

#include <iostream>

using namespace std;

/*	一对一友好关系（约束模板友元）
	为了引用（类或函数）模板的一个特定实例，我们必须首先声明模板自身
*/
// 前置声明，在Blob中声明友元所需要的
template <typename T>
class BlobPtr;
// 提前声明Blob类，因为运算符==中的参数所需要
template <typename T>
class Blob;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob
{
public:
	// 每个Blob实例将访问权限授予用相同类型实例化的BlobPtr和相等运算符
	friend class BlobPtr<T>;
	friend bool operator==(const Blob<T>&, const Blob<T>&);
};



/*	通用友好关系（非约束模板友元）
	为了让所有实例成为友元，友元声明中必须使用与类模板本身不同的模板参数
*/
// 前置声明，将模板的一个特定实例声明为友元时要用到
template <typename T>
class Pal;
// C是一个普通的非模板类
class C
{
public:
	// 用类C实例化的Pal是类C的一个友元
	friend class Pal<C>;
	// Pal2的所有实例都是C的友元，这种情况无须前置声明。
	template <typename T>
	friend class Pal2;
};
// C2是一个类模板
template <typename T>
class C2
{
public:
	// C2的每个实例将相同实例化的Pal声明为友元
	friend class Pal<T>;
	// Pal2的所有实例都是C2的每个实例的友元，这种情况无须前置声明。
	template <typename X>		// 为了让所有实例成为友元，友元声明中必须使用与类模板本身不同的模板参数
	friend class Pal2;
	// Pal3是一个非模板类，它是C2所有实例的友元
	friend class Pal3;
};

int main()
{
	// 友元的声明用Blob的模板形参作为它们自己的模板实参。因此，友好关系被限定在用相同类型实例化的Blob与BlobPtr相等运算符之间
	Blob<char> ca;
	Blob<int> ia;
	// 
	C c;
	C2<char> c2;
	return 0;
}



// tips:
//	1. 当一个类包含一个友元声明时，类与友元各自是否是模板是相互无关的。如果一个类模板包含一个非模板友元，则友元被授权可以访问所有模板实例。
//	如果友元自身是模板，类可以授权给所有友元模板实例，也可以只授权给特定实例。
//	2. 为了引用（类或函数）模板的一个特定实例，我们必须首先声明模板自身。一个模板声明包括模板参数列表。
//	3. 一个类也可以将另一个模板的每个实例都声明为自己的友元，或者限定特定的实例为友元。
//	为了让所有实例成为友元，友元声明中必须使用与类模板本身不同的模板参数