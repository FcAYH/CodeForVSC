#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int N = 0;
    scanf("%d", &N);

    int *nums = new int[N + 1];
    for (int i = 1; i <= N; i++)
        scanf("%d", &nums[i]);

    if (!(N % 2))
        printf("true");
    else
    {
        for (int i = 2; i <= N; i++)
            nums[1] ^= nums[i];
        printf("%s", (nums[1]) ? "false" : "true");
    }

    delete[] nums;
}

int main()
{
    Solve();

    return 0;
}
