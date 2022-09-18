#include <stdio.h>

int GetAboveAver(int score[], float *aver, int n)
{
    for (int i = 1; i <= n; i++)
        *aver += (float)score[i];
    *aver = *aver / (float)n;
}

void Solve()
{
    int score[50];
    int total = 1;
    scanf("%d", &score[1]);
    while (score[total] >= 0)
    {
        total++;
        scanf("%d", &score[total]);
    }

    total--;
    float Ave = 0.0;
    GetAboveAver(score, &Ave, total);

    printf("Total number is %d\n", total);
    printf("Average score is %.2f\n", Ave);

    int cnt = 0;
    for (int i = 1; i <= total; i++)
    {
        if ((float)score[i] > Ave)
            cnt++;
    }
    printf("%d students are above average score\n", cnt);
}

int main()
{
    Solve();

    return 0;
}
