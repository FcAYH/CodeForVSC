#include<bits/stdc++.h> 

using namespace std;

const int MaxN = 1510;

int nums[MaxN];

int main( )
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > nums[j])
                sum++;
        }
    }

    bool flag = sum % 2;
    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);

        int length = r - l + 1;
        if (((int)((length) * (length - 1) * 0.5)) % 2)
            flag = !flag;
        
        printf("%s\n", flag ? "odd" : "even");
    }

    return 0;
}
