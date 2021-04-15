#include <bits/stdc++.h>

using namespace std;

class A
{
    int x, y;
    ~A(){};

public:
    A(A &a)
    {
        x = a.x, y = a.y;
    }
    A(int a = 0, int b = 0)
    {
        x = a, y = b;
    }
    void destroy(int i)
    {
        if (i)
            delete[] this;
        else
            delete this;
    }
    int get_x() { return x; }
    int get_y() { return y; }
};

int main()
{
    //    A *p = new A[10];
    A *p = new A;

    return 0;
}
