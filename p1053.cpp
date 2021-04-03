#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=50010;

union hh{char ch[6];float a;float b;};
struct xx{double w;union hh u; float v[5];}vh;
int Dv1[Maxn],Dv2[Maxn];
int vis[Maxn];
int c[Maxn];
int l1[Maxn],l2[Maxn];
int si=1,n,ans=0;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Build()
{
	c[1]=1; c[2]=l1[1]; vis[c[1]]=vis[c[2]]=1;
	for(int i=2;i<=n-1;i++)
	{
		if(c[i-1]==l1[c[i]]) c[i+1]=l2[c[i]],vis[c[i+1]]=1;  
		else if(c[i-1]==l2[c[i]]) c[i+1]=l1[c[i]],vis[c[i+1]]=1;
		else 
		{
			si=0;
			printf("-1\n"); return ;
		}
	}
	for(int i=1;i<=n;i++) if(!vis[i]) si=0,printf("-1\n");
	if((c[1]==l1[c[n]]&&c[n-1]!=l2[c[n]])||(c[1]!=l1[c[n]]&&c[n-1]==l2[c[n]])) si=0,printf("-1\n");
	else if((c[1]==l2[c[n]]&&c[n-1]!=l1[c[n]])||(c[1]!=l2[c[n]]&&c[n-1]==l1[c[n]])) si=0,printf("-1\n");
			
}
void Simulation()
{
	for(int i=1;i<=n;i++)
	{
		Dv1[(c[i]-i+n)%n]++;
		Dv2[(c[n-i+1]-i+n)%n]++;
	}
	for(int i=0;i<=n-1;i++) ans=max(ans,max(Dv1[i],Dv2[i]));
	printf("%d\n",n-ans);
}
void read_ini()
{
	cout<<sizeof(vh)<<endl;
	n=read();
	for(int i=1;i<=n;i++) l1[i]=read(),l2[i]=read();
	Build();
	if(si) Simulation();
}
int main()
{
	read_ini();
	return 0;
}