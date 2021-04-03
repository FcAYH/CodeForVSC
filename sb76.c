#include <stdio.h>

void Solve()
{
    printf("这里是23根火柴游戏！！\n");
    printf("注意：最大移动火柴数目为三根\n");
    int total = 23;
    int n;
    while (total > 0)
    {
        printf("请输入移动的火柴数目：\n");
        scanf("%d", &n);
        while (n > 3 || n < 1)
        {
            printf("对不起！您输入了不合适的数目，请点击任意键重新输入！\n");
            printf("请输入移动的火柴数目：\n");
            scanf("%d", &n);
        }

        printf("您移动的火柴数目为：%d\n", n);
        printf("您移动后剩下的火柴数目为：%d\n", total - n);
        total -= n;

        if (total <= 0)
        {
            printf("对不起！您输了！\n");
            break;
        }

        int computer = (total - 1) % 4;
        (!computer) ? computer++ : computer;
        printf("计算机移动的火柴数目为：%d\n", computer);
        printf("计算机移动后剩下的火柴数目为：%d\n", total - computer);
        total -= computer;

        if (total <= 0)
        {
            printf("恭喜您！您赢了！ \n");
            break;
        }
    }
}

int main()
{
    Solve();

    return 0;
}
