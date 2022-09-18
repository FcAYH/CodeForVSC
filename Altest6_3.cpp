#include <stdio.h>
#include <string.h>
int cnt[26];
int Schedule(char task[], int n)
{
    int length = strlen(task);
    //计算每种任务需要执行的次数
    for (int i = 0; i < length; i++)
    {
        cnt[task[i] - 'A']++;
    }
    //寻找次数最多的任务maxTaskCnt，maxTasks记录次数最多的任务的个数
    int maxTaskCnt = 0, maxTasks = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] > maxTaskCnt)
        {
            maxTaskCnt = cnt[i];
            maxTasks = 1;
        }
        else if (cnt[i] == maxTaskCnt)
        {
            maxTasks++;
        }
    }
    //计算需要的最大时间
    int a = length - maxTaskCnt - maxTasks + 1; //需要插入的个数
    int b = n * (maxTaskCnt - 1);               //可插入利用的最大个数
    if (a < b)
    { //第一种情况，贪心策略，尽量插入间隔
        return (n + 1) * (maxTaskCnt - 1) + maxTasks;
    }
    else
    { //第二种情况，只要不让相同的任务的距离小于n即可
        return length;
    }
}
int main()
{
    int n;
    char task[100];
    printf("Please input n :");
    scanf("%d", &n);
    printf("Please input task :");
    scanf("%s", task);
    int ans = Schedule(task, n);
    printf("%d", ans);
    return 0;
}
/*
2 AAABBB
0 AAABBB
*/
