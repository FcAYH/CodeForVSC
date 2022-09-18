#include <stdio.h>

int Month[2][13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Check_Leap(int x)
{
    return (!(x % 4) && x % 100) || (!(x % 400));
}

void Solve()
{
    printf("请输入日期1（空格分隔，年月日）:\n");
    int y1, m1, d1;
    scanf("%d%d%d", &y1, &m1, &d1);

    printf("请输入日期2（空格分隔，年月日，晚于日期1）:\n");
    int y2, m2, d2;
    scanf("%d%d%d", &y2, &m2, &d2);

    int Day = 0;

    if (y1 == y2)
    {
        if (m1 == m2)
            Day = d2 - d1;
        else
        {
            Day += Month[Check_Leap(y1)][m1] - d1;
            for (int i = m1 + 1; i <= m2 - 1; i++)
                Day += Month[Check_Leap(y1)][i];
            Day += d2;
        }
    }
    else
    {
        for (int i = 12; i >= m1 + 1; i--)
            Day += Month[Check_Leap(y1)][i];
        Day += Month[Check_Leap(y1)][m1] - d1;

        for (int i = y1 + 1; i <= y2 - 1; i++)
            Day += (Check_Leap(i)) ? 366 : 365;

        for (int i = 1; i <= m2 - 1; i++)
            Day += Month[Check_Leap(y2)][i];
        Day += d2;
    }
    printf("相差天数为:");
    printf("\t%d天\n", Day);
}

int main()
{
    Solve();

    return 0;
}
