#include <bits/stdc++.h>

using namespace std;

class Test
{
public:
    int val;
    char *str;

public:
    Test(int x) : val(x)
    {
        cout << "ctor" << endl;
    }

    ~Test()
    {
        cout << "val: " << val << " free" << endl;
    }

    void ctor()
    {
        str = (char *)malloc(sizeof(char) * 6);
        cin >> str;
    }

    void fun1()
    {
        delete this;
        cout << "hello world" << endl;
    }

    virtual void fun2()
    {
        cout << "virtual fun" << endl;
    }
};

void Solve()
{
    // Test *p = (Test *)malloc(sizeof(p));
    // p->ctor();
    // free(p);
    // cout << p->str;
    // Test *p = new Test(2);
    // delete p;
    // p->fun1();
    // delete p;

    Test *q = nullptr;
    // cout << q->val << endl;
    q->fun1();
    q->fun2();
    delete q;
}

int main()
{
    Solve();

    return 0;
}
