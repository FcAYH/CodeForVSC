#include <bits/stdc++.h>

using namespace std;

class CppTest
{
public:
    int val;

    CppTest(int x) : val(x) {}
    ~CppTest()
    {
        cout << "free" << endl;
    }

    void FunA()
    {
        cout << val << endl;
        cout << "Hello world" << endl;
    }

    void FunB()
    {
        cout << "Good night" << endl;
    }
};

int main()
{
    CppTest *p = new CppTest(2);

    p->FunA();

    delete p;

    return 0;
}
