#include <cstdio>
using namespace std;
long long n, ans;
int main()
{
    scanf("%lld", &n);
    ans = n;
    for (long long i = 2; i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            ans = ans / i * (i - 1);
        }
    printf("%lld\n", ans);
}
