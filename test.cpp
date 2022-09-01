#include <bits/stdc++.h>

using namespace std;

class Test
{
public:
    Test()
    {
        cout << "ctor" << endl;
    }

    ~Test()
    {
        cout << "free" << endl;
    }

    void fun1()
    {
        delete this;
        cout << "hello world" << endl;
    }
};

void Solve()
{
    Test *p = new Test();
    delete p;
    p->fun1();
    delete p;

    Test *q = nullptr;
    q->fun1();
    delete q;
}

int main()
{
    Solve();

    return 0;
}
