#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long sum[1001000];
void Solve()
{
    sum[1] = 1;
    for (int i = 2; i <= 1000000; i++)
        sum[i] = sum[i - 1] + i;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long a, b, c, d, ans = 0;
        scanf("%lld%lld", &a, &b);
        if (a == b)
        {
            printf("0\n");
            continue;
        }
        c = min(a, b);
        a -= c, b -= c;
        d = max(a, b);
        for (int i = 1; i <= 1e6; i++)
        {
            if (sum[i] >= d && (sum[i] + d) % 2 == 0)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
#include <iostream>
#include <cstdio>
using namespace std;
long long sum[1001000];
int main()
{
	sum[1] = 1;
	for(int i = 2; i <= 1e6; i++)
		sum[i] = sum[i-1] + i;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long a,b,c,d,ans = 0;
		scanf("%lld%lld",&a,&b);
		if(a == b)
		{
			printf("0\n");
			continue;
		}
		c = min(a, b);
		a -= c, b -= c;
		d = max(a, b);
		for(int i = 1; i <= 1e6; i++)
			if(sum[i] >= d && (sum[i] + d) % 2 == 0)
			{
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}
*/