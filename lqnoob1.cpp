#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 1001000;
const int Mod = 10007;
int n;
int f[Maxn];
void Solve()
{
    scanf("%d", &n);
    f[1] = 1, f[2] = 1;
    for (register int i = 3; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]), f[i] = f[i] - f[i] / Mod * Mod;
    printf("%d", f[n]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}