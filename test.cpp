
#include <bits/stdc++.h>

using namespace std;

class A
{

    int x, y;

public:
    A(int a = 0, int b = 0) : x(a), y(b) { cout << "A"; }

    int getx() { return x; }

    int gety() { return y; }

    ~A() { cout << "B"; }
};

class B
{

    A a1, a2;

    const int k;

public:
    B(int x1, int y1, int x2, int y2) : a1(x1, y1), a2(x2, y2), k(10) { cout << "C"; }

    B() : k(5) { cout << "D"; }

    void outa1() { cout << a1.getx() << a1.gety(); }

    void outa2() { cout << a2.getx() << a2.gety(); }

    int getk() { return k; }

    ~B() { cout << "E"; }
};

int main()
{

    B b1, b2(1, 2, 3, 4);

    b1.outa1();
    b1.outa2();
    cout << b1.getk();

    b2.outa1();
    b2.outa2();
    cout << b2.getk();
}
