#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("out.txt", "r", stdin);

    int cnt[5] = {0, 0, 0, 0, 0};
    //srand(time(0));
    for (int i = 1; i <= 80; i++)
    {
        int x;
        scanf("%x,", &x);
        //printf("%d ", x);
        if (x >= 90)
            cnt[0]++;
        else if (x >= 80)
            cnt[1]++;
        else if (x >= 70)
            cnt[2]++;
        else if (x >= 60)
            cnt[3]++;
        else
            cnt[4]++;
        //printf("0x%x, ", rand() % 100 + 1);
    }
    printf("%d %d %d %d %d \n", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]);
}
//6 13 11 9 41
