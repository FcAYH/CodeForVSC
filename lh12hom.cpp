#include <iostream>
using namespace std;
class GfG
{
private:
    static int ci;
    int a;

public:
    GfG() { a = 0, ci++; }
    GfG(int x) { a = x; }
    GfG(GfG &t) { a = t.a; }
    ~GfG(){};
    static void print() { printf("%d", ci); }
};
int GfG ::ci = 0;

int main()
{
    GfG obj1;

    GfG obj2(obj1);

    system("pause");
    return 0;
}
