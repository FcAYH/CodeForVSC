#include <stdio.h>
#include <string.h>

unsigned int InputNumber(char ch)
{

    char s[20];

    while (1)
    {
        printf("Please input the number %c(>1):", ch);
        scanf("%s", s);
        int len = strlen(s);
        if (s[0] == 0 || s[0] == '-')
        {
            printf("The input must be an integer larger than 1!\n");
            continue;
        }

        int num = 0, flag = 0;
        for (int i = 0; i <= len - 1; i++)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                printf("The input must be an integer larger than 1!\n");
                flag = 1;
            }
            if (flag)
                break;
            num = num * 10 + s[i] - '0';
        }

        if (flag)
            continue;
        else if (num == 1)
            printf("The input must be an integer larger than 1!\n");
        else
            return num;
    }
    return 0;
}
int IsPrime(unsigned int n)
{
    for (int i = 2; i * i <= n; i++)
        if (!(n % i))
            return 0;
    return 1;
}

int PrimeSum(unsigned int m, unsigned int n)
{
    int ans = 0;
    for (int i = m; i <= n; i++)
        if (IsPrime(i))
            printf("%d\n", i), ans += i;
    return ans;
}

int main()
{
    int m = 0, n = 0, sum = 0, i = 0;

    do
    {
        m = InputNumber('m');
        n = InputNumber('n');
    } while (m > n && printf("n must be not smaller than m! Input again!\n")); //保证m<=n

    sum = PrimeSum(m, n);
    printf("sum of prime numbers:%d", sum);
    return 0;
}
