#include <stdio.h>
void ReadScore(int Score[])
{
    for (int i = 1; i <= 10; i++)
    {
        scanf("%d", &Score[i]);
    }
}
void MaxMin(int Score[], int *MaxNum, int *MinNum)
{
    int Max = 0, Min = 10;
    for (int i = 1; i <= 10; i++)
    {
        if (Score[i] > Max)
            Max = Score[i], *MaxNum = i;
        if (Score[i] < Min)
            Min = Score[i], *MinNum = i;
    }
}
main()
{
    int Score[12];
    ReadScore(Score);
    int MaxNum = 10, MinNum = 0;
    //for (int i = 1; i <= 10; i++)
    //   printf("%d ", Score[i]);
    MaxMin(Score, &MaxNum, &MinNum);
    printf("最高分为第%d个评委，最低分为第%d个评委\n", MaxNum, MinNum);
    return 0;
}
