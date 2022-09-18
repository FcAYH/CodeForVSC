#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Mod = 1000000007;
const int Maxn = 1000010;

void Solve()
{

    int t, Hour, Minute;
    char AP[10];
    char City1[20], City2[20];
    scanf("%d", &t);
    for (int T = 1; T <= t; T++)
    {
        scanf("%d:%d", &Hour, &Minute);
        scanf("%s", AP);
        scanf("%s%s", City1, City2);
        if (AP[0] == 'A' && Hour == 12)
            Hour = 0;
        else if (AP[0] == 'P' && Hour != 12)
            Hour += 12;
        if (City1[0] == 'W')
            Hour += 5;
        else if (City1[0] == 'M')
            Hour -= 3;
        else if (City1[0] == 'B')
            Hour -= 8;

        if (City2[0] == 'W')
            Hour -= 5;
        else if (City2[0] == 'M')
            Hour += 3;
        else if (City2[0] == 'B')
            Hour += 8;

        printf("Case %d: ", T);

        if (Hour < 0)
            Hour += 24, printf("Yesterday ");
        else if (Hour >= 24)
            Hour -= 24, printf("Tomorrow ");
        else
            printf("Today ");
        if (Hour == 0)
            printf("12:%02d AM\n", Minute);
        else if (Hour >= 1 && Hour < 12)
            printf("%d:%02d AM\n", Hour, Minute);
        else if (Hour == 12)
            printf("12:%02d PM\n", Minute);
        else
            printf("%d:%02d PM\n", Hour - 12, Minute);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
100
4:00 PM
London
Beijing
4:00 PM
London
Beijing
6:34 PM
Washington
Beijing
12:00 AM
London
Moscow
4:00 PM
London
Beijing
*/