#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 100009;

int fa[maxn],a[maxn],mn[maxn];
map<string,int> mp;
int n,m,k;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void merge(int x,int y)
{
	int t=a[y],fat=find(y);
	fa[fat]=find(x);
	mn[find(x)]=min(mn[find(x)],t);
}

int main()
{
	n=read();k=read();m=read();
	for(int i=1;i<=n;i++)
	{
		string t;cin>>t;
		mp[t]=i;
	}
	for(int i=1;i<=n;i++) mn[i]=a[i]=read(),fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		int t=read(),x=read();
		for(int j=2;j<=t;j++) merge(x,read());
	}
	long long sum=0;
	for(int i=1;i<=m;i++)
	{
		string t;cin>>t;
		sum+=mn[find(mp[t])];
	}
	cout<<sum<<endl;
	return 0;
}
