#include <bits/stdc++.h>

using namespace std;
struct arr_time
{
    int hour, min, second;
    int pro;
};
int cmp(arr_time a, arr_time b)
{
    if (a.hour != b.hour)
        return a.hour < b.hour;
    else if (a.min != b.min)
        return a.min < b.min;
    else if (a.second != b.second)
        return a.second < b.second;
    return true;
}
arr_time customer[10001];
arr_time begin_Hour, last_Hour;
int wa[10001];
arr_time fre[101];
int cal_time(arr_time a)
{
    return a.hour * 3600 + a.min * 60 + a.second;
}
arr_time cal_time(arr_time a, int min)
{
    a.min += min;
    if (a.min >= 60)
    {
        a.hour++;
        a.min %= 60;
    }

    return a;
}
int wait_time(arr_time a, arr_time b)
{
    return abs((a.hour * 3600 + a.min * 60 + a.second) - (b.hour * 3600 + b.min * 60 + b.second));
}
void Solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%d:%d:%d %d", &customer[i].hour, &customer[i].min, &customer[i].second, &customer[i].pro);

    sort(customer, customer + n, cmp);

    begin_Hour.hour = 8;
    last_Hour.hour = 17;

    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d pro: %d\n", customer[i].hour, customer[i].min, customer[i].second, customer[i].pro);
    }

    for (int i = 0; i < n; i++)
    {
        if (cmp(customer[i], begin_Hour))
        {
            wa[i] = wait_time(customer[i], begin_Hour);

            int pro = customer[i].pro;
            customer[i] = begin_Hour;
            customer[i].pro = pro;
        }

#pragma region 正常处理流程

        /*找空位
        if 有空位 就放上
            没有 就找最近结束的位置 计算wa
        更新结束时间
        */
        arr_time latest = fre[0];
        bool flag = false;
        int pos = -1;

        // 找到第i个客户，应该被在哪个窗口被服务
        for (int j = 0; j < k; j++)
        {
            printf("%d: %d %d %d\n", j, fre[j].hour, fre[j].min, fre[j].second);
            // 找到空位
            if (cmp(fre[j], customer[i]))
            {
                flag = true;
                pos = j;
                break;
            }

            // 如果没有空位，我们找最近的
            if (cmp(fre[j], latest))
            {
                latest = fre[j];
                pos = j;
            }
        }

        printf("<%d> ", pos);
        if (!flag)
        {
            wa[i] += wait_time(fre[pos], customer[i]);
        }

        printf("-- %d %d %d %d\n", customer[i].hour, customer[i].min, customer[i].second, customer[i].pro);
        fre[pos] = cal_time(customer[i], min(customer[i].pro, 60));
        printf("---- %d: %d %d %d\n", pos, fre[pos].hour, fre[pos].min, fre[pos].second);

#pragma endregion

        if (cmp(last_Hour, customer[i]))
        {
            break;
        }
    }
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += wa[i];
        printf("%d ", wa[i]);
    }
    printf("%f", sum / 60 / (n - 1));
}

int main()
{
    Solve();

    return 0;
}
