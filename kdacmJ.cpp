#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const ll Mod = 1000000007;
const int MaxL = 100010;
ll Ans = 1;
char s[MaxL + 10];
ll F[MaxL + 10];
void Ini_Fib()
{
    F[1] = 1ll, F[2] = 1ll;
    for (int i = 3; i <= MaxL; i++)
        F[i] = F[i - 1] + F[i - 2], F[i] %= Mod;
}
inline void CALC(int x)
{
    Ans *= F[x + 1], Ans %= Mod;
}
void Solve()
{
    Ini_Fib();
    cin >> (s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
        if (s[i] == 'm' || s[i] == 'w')
        {
            printf("0\n");
            return;
        }
    int cnt = 0;
    char si = s[1];
    for (int i = 1; i <= len; i++)
    {
        if (s[i] == 'n')
        {
            if (si == 'n')
                cnt++;
            else
                CALC(cnt), si = 'n', cnt = 1;
        }
        else if (s[i] == 'u')
        {
            if (si == 'u')
                cnt++;
            else
                CALC(cnt), si = 'u', cnt = 1;
        }
        else
            CALC(cnt), si = s[i], cnt = 0;
    }
    CALC(cnt);
    printf("%lld\n", Ans);
}
int main()
{
    Solve();
    return 0;
}