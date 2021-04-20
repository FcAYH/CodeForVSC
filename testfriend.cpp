#include <bits/stdc++.h>

using namespace std;
// class B;
// class A
// {
//     int val;

// private:
//     friend B;
// };
// class B
// {
// public:
//     void print(A t)
//     {
//         printf("%d", t.val);
//     }
// }
class A
{

    int x, y;

public:
    friend int f1(A &);
    friend int f2(A &);
    A(int a, int b) : x(a), y(b) {}

    int getx() { return x; }

    int gety() { return y; }
};

int f1(A &a) { return a.x + a.y; }

int f2(A &a)
{
    A b(a.x * a.x, a.y * a.y);
    return b.x + b.y;
}
