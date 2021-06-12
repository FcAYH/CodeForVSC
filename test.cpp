#include <bits/stdc++.h>

using namespace std;

class A
{
    int x;
    int a1;

protected:
    int a2;

public:
    int a3;
    void Pcs()
    {
        printf("%d\n", this->x);
    }
    A() {}
    A(int x) : x(x) {}

    A operator+(A &a)
    {
        x += a.x;
        return *this;
    }
    // int operator+(int, int);

    // void operator+(A &, int);

    // A operator+(A &, A &, int);

    // A A::operator+(int);

    // void operator++(A &);

    // A operator++(A &, int);

    // A A::operator++();

    // A A::operator++(int);

    //......
};

class B : protected A
{

    int b1;

protected:
    int b2;

public:
    int b3;

    //....
};

class C
{

    int c1;

protected:
    int c2;

public:
    int c3;

    //....
};

class D : public B
{

    int d1;

protected:
    int d2;

    C cob1, cob2;

public:
    int d3;

    void f();
};

int main()
{
    A a(2), b(3), c(0);
    A e;
    e(a);
    // a + b;
    // c = a + b;
    // operator+(a, b);
    // a.

    c = a + b;
    a.Pcs(), b.Pcs(), c.Pcs();

    c = a.operator+(b);
    a.Pcs(), b.Pcs(), c.Pcs();

    return 0;
}
