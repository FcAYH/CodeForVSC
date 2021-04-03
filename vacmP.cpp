#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int Maxn = 1000010;
ll m, a, c, g;
int n;
ll X[Maxn];
void Solve()
{
    scanf("%lld%lld%lld%lld%d%lld", &m, &a, &c, &X[0], &n, &g);
    for (int i = 1; i <= n; i++)
        X[i] = (a * X[i - 1] + c) % m;
    printf("%lld\n", X[n] % g);
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}