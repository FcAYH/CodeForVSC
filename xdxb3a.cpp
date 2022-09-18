#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int Maxn=2000000;
const int Maxm=50; 
const int Hex=233;
const int Mod=1060421;
queue <int> q;
int n,num;
int num1=0,num2=0;
int head[Maxn];
bool flag,vis[Maxn];
char s1[Maxm],s2[Maxm];
char ans1[Maxm],ans2[Maxm];
struct list{int to,next;}E[Maxn];
void add_edge(int x,int y)
{
	E[++num].to=y,E[num].next=head[x],head[x]=num;
}
int Make_Hash1()
{
	int len=strlen(s1),Id=0;
	for(int i=0;i<len;i++)
	{
		Id=(Id*Hex+s1[i])%Mod;
	}
	return Id;
}
int Make_Hash2()
{
	int len=strlen(s2),Id=0;
	for(int i=0;i<len;i++)
	{
		Id=(Id*Hex+s2[i])%Mod;
	}
	return Id;
}
inline void Array_Ini()
{
    num=0;
    memset(E,0,sizeof(E));
    memset(head,0,sizeof(head));
}
void dfs(int x)
{
//	cout<<x<<endl;
	if(flag)	return;
    for(int i=head[x];i;i=E[i].next)
    {
        int qt=E[i].to;
        if(qt==num1 || qt==num2)
        {
        	flag=1;
        	return;
		}
    	dfs(qt);
    }
}
void Solve()
{
    while(scanf("%d",&n)!=EOF)
	{
		int ans=0;
        Array_Ini();
		for(int i=1;i<=n;i++)
		{
			memset(s1,0,sizeof(s1));
            memset(s2,0,sizeof(s2));
			scanf("%s%s",s1,s2);
			if(ans)	continue;
            memset(ans1,0,sizeof(ans1));
            memset(ans2,0,sizeof(ans2));
            memset(vis,0,sizeof(vis));
			int len1=strlen(s1),len2=strlen(s2);
			num1=0,num2=0;
            num1=Make_Hash1();
            num2=Make_Hash2();
			add_edge(num2,num1);
			flag=0;
			dfs(num1);
            if(flag)
            {
                ans=i;
                swap(s1,ans1),swap(s2,ans2);
            }
		}
		if(!ans) printf("0\n");
		else printf("%s %s\n",ans1,ans2);
	}
}
int main()
{
    Solve();
    return 0;
}
/*
1
1 2
5
1 2
2 3
3 4
4 5
5 6
6
1 5
2 5
3 5
3 4
4 5
5 2
7
1 2
2 3
3 4
4 8
1 6
6 7
7 8
*/