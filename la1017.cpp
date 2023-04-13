#include <bits/stdc++.h>

using namespace std;

const int MaxN = 10010;
const int MaxK = 110;

struct ArrTime
{
    int hour, minute, second;
    int processTime;

    ArrTime() : hour(8), minute(0),
                second(0), processTime(0) {}
    ArrTime(int hour) : hour(hour), minute(0),
                        second(0), processTime(0) {}

    int totalSeconds()
    {
        return hour * 3600 + minute * 60 + second;
    }
};

ArrTime customers[MaxN];
ArrTime window[MaxK];
int wait[MaxN];

bool cmp(ArrTime a, ArrTime b)
{
    if (a.hour != b.hour)
        return a.hour < b.hour;
    else if (a.minute != b.minute)
        return a.minute < b.minute;
    else
        return a.second <= b.second;
}

int calc_wait(ArrTime a, ArrTime b)
{
    if (!cmp(a, b))
        swap(a, b);

    return b.totalSeconds() - a.totalSeconds();
}

ArrTime add_minute(ArrTime a, int min)
{
    a.minute += min;
    if (a.minute >= 60)
    {
        a.hour++;
        a.minute -= 60;
    }

    return a;
}

void Solve()
{
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d%d", &customers[i].hour, &customers[i].minute,
              &customers[i].second, &customers[i].processTime);
    }

    sort(customers, customers + n, cmp);

    ArrTime startTime(8);
    ArrTime endTime(17);
    endTime.second = 1;

    for (int i = 0; i < n; i++)
    {
        if (cmp(customers[i], startTime))
        {
            wait[i] += calc_wait(startTime, customers[i]);
            int pro = customers[i].processTime;
            customers[i] = startTime;
            customers[i].processTime = pro;
        }

        if (cmp(endTime, customers[i]))
        {
            n = i;
            break;
        }
    }

    if (n == 0)
    {
        printf("0.0");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // printf("%d customer arrived at %d %d %d, pro %d\n", i, customers[i].hour, customers[i].minute, customers[i].second, customers[i].processTime);
        int pos = 0;
        ArrTime latest = window[0];

        // for (int j = 0; j < k; j++)
        //     printf("%d %d %d\n", window[j].hour, window[j].minute, window[j].second);

        for (int j = 0; j < k; j++)
        {
            if (cmp(window[j], customers[i])) // 有空闲窗口
            {
                pos = j;
                break;
            }

            if (cmp(window[j], latest)) // 无空闲窗口时选择最早结束的
            {
                latest = window[j];
                pos = j;
            }
        }

        if (!cmp(window[pos], customers[i])) // 没有空闲窗口，计算等待时长
        {
            wait[i] += calc_wait(window[pos], customers[i]);
        }

        // printf("%d customer is served at %d window\n", i, pos);

        window[pos] = add_minute(
            cmp(window[pos], customers[i]) ? customers[i] : window[pos], min(60, customers[i].processTime));
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // printf("%d ", wait[i]);
        sum += wait[i];
    }
    printf("%.1lf", (double)sum / n / 60.0);
}

int main()
{
    Solve();

    return 0;
}
