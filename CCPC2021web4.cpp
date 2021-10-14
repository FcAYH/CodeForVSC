#include <bits/stdc++.h>

using namespace std;

// bool Not_p[10000010];
// int prime[10000010];
// int len = 0;
// void Prime_Ini()
// {
//     Not_p[1] = 1;
//     for (int i = 2; i <= 10000000; i++)
//     {
//         if (!Not_p[i])
//             prime[++len] = i;
//         for (int j = 1; j <= len; j++)
//         {
//             if (prime[j] * i > 10000000)
//                 break;
//             Not_p[i * prime[j]] = 1;
//             if (!(i % prime[j]))
//                 break;
//         }
//     }
// }

void Solve()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        long long x;
        scanf("%lld", &x);
        if (x == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    // Prime_Ini();
    // for (int i = 1; i <= len; i += 2)
    // {
    //     if (!Not_p[(prime[i] + prime[i + 1]) / 2])
    //         printf("Yes");
    // }
    //else
    //printf("No");
}

int main()
{
    Solve();

    return 0;
}
