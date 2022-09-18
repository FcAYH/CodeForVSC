#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read()
{
    int fl = 1, rt = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            fl = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        rt = rt * 10 + ch - '0';
        ch = getchar();
    }
    return fl * rt;
}

void Solve()
{
    int T = read();
    while (T--)
    {
        int n = read();
        int ans = 0;

        int highest = 2 * n;
        int numberCounts = highest - (n + 1) + 1;
        if (numberCounts % 2 == 0)
            ans += numberCounts / 2;
        else
        {
            if (highest % 2 == 0)
                ans += numberCounts / 2 + 1;
            else
                ans += numberCounts / 2;
        }

        //printf("%d ", ans);

        int lowest = ceil(n / 3.0);
        numberCounts = n - lowest + 1;
        if (numberCounts % 2 == 0)
            ans += numberCounts / 2;
        else
        {
            if (n % 2 == 0)
                ans += numberCounts / 2;
            else
                ans += numberCounts / 2 + 1;
        }

        printf("%d\n", ans);
    }
}

int main()
{
    Solve();

    return 0;
}

/*
4
12
13
60
101010101

12

24 22 20 18 26 14 

14 12 10 8 6 
5 7 9 11 

13 14

26 24 22 20 18 16 14
13 11 9 7 5 
*/
