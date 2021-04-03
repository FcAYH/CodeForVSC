#include<bits/stdc++.h>
using namespace std;
const int Maxn=100010;
int n,m,a,b,k,t,d,f;
int city[Maxn];
int Map[Maxn][2];
void Solve()
{
    scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
    {
		scanf("%d%d",&a,&b);
		Map[i][0]=a,Map[i][1]=b;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
    {
		f=1;
		for(int i=1;i<=n;i++) city[i]=1;
		scanf("%d",&t);
		for(int j=0;j<t;j++) scanf("%d",&d),city[d] = 0;
		for(int j=0;j<m;j++)
        {
			if(city[Map[j][0]]==1&&city[Map[j][1]]==1)
            {
				f=0;
				printf("NO\n");
				break;
			}
		}
		if(f==1) printf("YES\n");
	}
}
int main()
{			
    Solve();
    system("pause");
	return 0;
}