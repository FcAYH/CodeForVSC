#include <stdio.h>

int fun(int score[], int m, int below_score[], int below_index[])
{
    int sum = 0;
    for (int i = 1; i <= m; i++)
        sum += score[i];

    int cnt = 0;
    int average = sum / m;
    for (int i = 1; i <= m; i++)
    {
        if (score[i] < average)
            below_score[++cnt] = score[i],
            below_index[cnt] = i;
    }
    return cnt;
}
int ReadScore(int score[])
{
    int x, cnt = 0;
    scanf("%d", &x);
    if (x == -1)
        printf("there are no valid scores\n");

    while (x != -1)
    {
        score[++cnt] = x;
        scanf("%d", &x);
    }
    return cnt;
}

void Solve()
{
    int score[40];
    int cnt = ReadScore(score);

    int below_score[40], below_index[40];
    int num = fun(score, cnt, below_score, below_index);

    printf("the number of the class:%d\n", cnt);
    printf("the number under the average score: %d\n", num);
    for (int i = 1; i <= num; i++)
        printf("the %dth score is: %d\n", below_index[i], below_score[i]);
}

int main()
{
    Solve();

    return 0;
}
