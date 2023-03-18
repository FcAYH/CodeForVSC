#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxN 10000000

double nums[MaxN];

void Solve()
{
    srand(time(0));

    for (int i = 0; i < MaxN; i++)
    {
        nums[i] = rand() % 1000;
    }

    /*
        我需要一段代码，实现以下功能：
        1. nums[i] = sqrt(nums[i]);
        2. 统计总共的耗时
    */

    // 以下代码是我写的，但是我不知道为什么，总是会报错
    // 请帮我修改一下，谢谢
    // 请在这里写下你的代码
    clock_t start, end;
    start = clock();
    for (int j = 0; j < 100; j++)
    {
        for (int i = 0; i < MaxN; i++)
        {
            sqrtl(nums[i]);
        }
    }
    end = clock();
    printf("Time: %lf\n", (double)(end - start));

    start = clock();
    for (int j = 0; j < 100; j++)
    {
        for (int i = 0; i < MaxN; i++)
        {
            sqrt(nums[i]);
        }
    }
    end = clock();
    printf("Time: %lf\n", (double)(end - start));
}

int main()
{
    Solve();

    return 0;
}
