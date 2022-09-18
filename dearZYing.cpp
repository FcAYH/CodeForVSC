#include <iostream>
#include <cstring>
using namespace std;
template <class T>
T *Max(T *a, T *b)
{
    if (a > b)
        return b;
    return a;
}

int main()
{
    int a = 3, b = 4;
    char m[12] = "ahfk", n[10] = "shfk";
    cout << "最大值为：" << *Max(&a, &b) << endl;
    cout << "最大值为：" << Max(m, n) << endl;

    return 0;
}
