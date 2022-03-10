#include <bits/stdc++.h>
using namespace std;
const int limitbit = 1826;
const int limitgold = 1265;

const int Maxn = 2000;
double dp[Maxn][2], f[Maxn][2];

struct Answer
{
    double count;
    int fromDay;
};
Answer pre[Maxn][2];

int sgn[Maxn];
struct pro
{
    int year, month, day;
    double bit, gold;
} Data[2000];
int tot = 0;

bool cmp(pro a, pro b)
{
    if (a.year == b.year)
    {
        if (a.month == b.month)
            return a.day < b.day;
        return a.month < b.month;
    }
    return a.year < b.year;
}
int main()
{
    // freopen("Data.txt", "r", stdin);
    // freopen("dream.txt", "w", stdout);
    // for (int i = 1; i <= limitbit; i++)
    // {
    //     int year, month, day;
    //     double val;
    //     scanf("%d/%d/%d%lf", &month, &day, &year, &val);
    //     int tar = 0;
    //     for (int j = 1; j <= tot; j++)
    //         if (Data[j].year == year && Data[j].month == month && Data[j].day == day)
    //         {
    //             tar = j;
    //             break;
    //         }
    //     if (tar == 0)
    //     {
    //         Data[++tot].year = year;
    //         Data[tot].month = month;
    //         Data[tot].day = day;
    //         Data[tot].bit = val;
    //     }
    //     else
    //     {
    //         cout << tar << "!!!\n";
    //     }
    // }
    // for (int i = 1; i <= limitgold; i++)
    // {
    //     int year, month, day;
    //     double val;
    //     scanf("%d/%d/%d%lf", &month, &day, &year, &val);
    //     int tar = 0;
    //     for (int j = 1; j <= tot; j++)
    //         if (Data[j].year == year && Data[j].month == month && Data[j].day == day)
    //         {
    //             tar = j;
    //             break;
    //         }
    //     if (tar == 0)
    //     {
    //         Data[++tot].year = year;
    //         Data[tot].month = month;
    //         Data[tot].day = day;
    //         Data[tot].bit = val;
    //     }
    //     else
    //     {
    //         Data[tar].gold = val;
    //     }
    // }

    tot = 4;
    Data[1].year = 21;
    Data[1].month = 2;
    Data[1].day = 14;
    Data[1].gold = 100;
    Data[1].bit = 1;
    Data[2].year = 21;
    Data[2].month = 2;
    Data[2].day = 15;
    Data[2].gold = 100;
    Data[2].bit = 100;
    Data[3].year = 21;
    Data[3].month = 2;
    Data[3].day = 16;
    Data[3].gold = 100;
    Data[3].bit = 1;
    Data[4].year = 21;
    Data[4].month = 2;
    Data[4].day = 17;
    Data[4].gold = 100;
    Data[4].bit = 100;

    sort(Data + 1, Data + 1 + tot, cmp);
    // for (int i = 1; i <= tot; i++)
    // {
    //     cout << Data[i].month << "/" << Data[i].day << "/" << Data[i].year << "\t" << Data[i].bit << "\t" << Data[i].gold << endl;
    // }
    for (int i = 1; i <= tot; i++)
        dp[i][0] = dp[i][1] = 1;
    //	dp[1][0] = dp[1][1] = 1000;
    int tst = tot;
    for (int i = 2; i <= tst; i++)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        pre[i][0].fromDay = i - 1;
        pre[i][0].count = 0;
        pre[i][1].fromDay = i - 1;
        pre[i][1].count = 0;
        for (int j = 1; j < i; j++)
        {

            double now = max(dp[j][0], dp[j][1]);
            if (Data[i].bit > 0 && Data[j].bit > 0)
            {
                double temp = now * 50.0 / 51.0 / Data[j].bit;
                if (temp * Data[i].bit * 0.98 > dp[i][0])
                {
                    dp[i][0] = temp * Data[i].bit * 0.98;
                    pre[i][0].fromDay = j; // sgn[i] = 0;
                    pre[i][0].count = temp;
                }
            }
            if (Data[i].gold > 0 && Data[j].gold > 0)
            {
                double temp = now * 100.0 / 101.0 / Data[j].gold;
                if (temp * Data[i].gold * 0.99 > dp[i][1])
                {
                    dp[i][1] = temp * Data[i].gold * 0.99;
                    pre[i][1].fromDay = j; // sgn[i] = 1;
                    pre[i][1].count = temp;
                }
            }
            sgn[i] = (dp[i][0] > dp[i][1]) ? 0 : 1;
        }
    }

    int nowDay = tst;
    while (nowDay > 1)
    {
        if (sgn[nowDay] == 0) // bit
        {
            if (pre[nowDay][0].count != 0)
            {
                printf("On the %d day, earn %f$ by saleing %lf bits brought from %d day.\n",
                       nowDay, dp[nowDay][0], pre[nowDay][0].count, pre[nowDay][0].fromDay);
            }
            else
            {
                printf("On the %d day, do nothing.\n", nowDay);
            }
            nowDay = pre[nowDay][0].fromDay;
        }
        else // gold
        {
            if (pre[nowDay][1].count != 0)
            {
                printf("On the %d day, earn %f$ by saleing %lf gold brought from %d day.\n",
                       nowDay, dp[nowDay][1], pre[nowDay][1].count, pre[nowDay][1].fromDay);
            }
            else
            {
                printf("On the %d day, do nothing.\n", nowDay);
            }
            nowDay = pre[nowDay][1].fromDay;
        }
    }

    cout << "bit  : ";
    printf("%.4lf\n", dp[tst][0]);
    cout << "gold : ";
    printf("%.4lf\n", dp[tst][1]);
}
/*
dp[i][0]  在第i天卖了比特币得到的钱，  f[i][0]  在前i天里最多能买多少黄金
dp[i][1]  在第i天卖了黄金得到的钱，    f[i][1]  在前i天最多能买多少比特币
*/
