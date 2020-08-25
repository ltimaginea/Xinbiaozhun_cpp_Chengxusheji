﻿// reference:   “引用”相当于变量的一个别名
// 定义“引用”方式如下:
// 类型名& 引用名 = 同类型的某变量名

#include <iostream>
using namespace std;

char m = 'X';
char& Swap(int& a, int& b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;

    return m;
}

int main()
{
    // 定义引用时一定要将其初始化，否则编译无法通过。
    // 通常以某个变量去初始化引用，或者用一个引用去初始化另一个引用，但不能用常量初始化引用。
    // 初始化后，它就一直引用该变量，不会再引用别的变量。
    int n = 1;
    int& r = n;
    cout << "n=" << n << " r=" << r << endl;                                    // 输出 n=1 r=1
   
    int n2 = 10;
    r = n2;
    n2 = 11;
    cout << "n2=" << n2 << " r=" << r << endl;                                  //输出 n2=11 r=10，说明 r 不会再去引用变量 n2

    // const T& 和 T& 是不同的类型。
    // T& 类型的引用或者 T 类型的变量可以用来初始化 const T& 类型的引用，
    // const T 类型的常变量和 const T& 类型的常引用则不能用来初始化 T& 类型的引用，除非进行强制类型转换。
    // 不能通过常引用去修改其引用的内容。但可以用别的方法修改，例如通过普通引用修改。
    const int& r2 = r;
    cout << "n=" << n << " r=" << r << " r2=" << r2 << endl;                    // 输出 n=10 r=10 r2=10
    // r2 = 20;                                                                 // 不能通过常引用去修改其引用的内容
    r = 20;                                                                     // 可以通过普通引用修改其引用的内容
    cout << "n=" << n << " r=" << r << " r2=" << r2 << endl;                    // 输出 n=20 r=20 r2=20
    int& r3 = (int&)r2;                                                         // 强制类型转换
    r3 = 30;
    cout << "n=" << n << " r=" << r << " r2=" << r2 << " r3=" << r3 << endl;    // 输出 n=30 r=30 r2=30 r3=30
    
    int m1 = 100, m2 = 200;
    Swap(m1, m2) = 'Y';
    cout << "m1=" << m1 << " m2=" << m2 << " m=" << m << endl;                  // 输出 m1=200 m2=100 m=Y
    return 0;
}