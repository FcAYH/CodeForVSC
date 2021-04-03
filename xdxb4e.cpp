#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int pos[200200];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,l,r;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			pos[x]=i;
			if(x==1) l=i,r=i;
		}
		printf("1");
		for(int i=2;i<=n;i++)
		{
			l=min(pos[i],l);
			r=max(pos[i],r);
			if(r-l+1==i) printf("1");
			else printf("0");
		}
		printf("\n");
	}
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
