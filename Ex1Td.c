#include <stdio.h>

unsigned int mod(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int ret = 0;
    for (int i = 30; i >= 0; i--)
    {
        if (b & (1 << i))
        {
            unsigned int temp = a;
            for (int j = 1; j <= i; j++)
                temp = (temp * 2) % c;
            ret += temp;
        }
    }
    return ret % c;
}

void Solve()
{
    unsigned int a, b, c;
    printf("Input unsigned intgers a,b and c:\n");
    scanf("%u%u%u", &a, &b, &c);

    unsigned int ans = mod(a, b, c);
    printf("%u*%u%%%u=%u\n", a, b, c, ans);
}

int main()
{
    Solve();

    return 0;
}
