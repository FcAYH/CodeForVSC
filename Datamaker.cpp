#include <cstdio>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    freopen("10.in", "w", stdout);
    srand(time(0));
    int n = 50000;
    printf("%d\n", n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", rand() % 100000);
    }
    return 0;
}
