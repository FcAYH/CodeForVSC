#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=200;
int T,n,ans=0;
int Girl[Maxn];
inline int read()
{
	int fl=1,rt=0; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0';ch=getchar();}
	return fl*rt;
}
void DeleteGirl(int x,int y)
{
    int Up=0;
    Girl[0]=-1;
    for(int i=1;i<=n;i++)
    {
        if(i==x)
        {
            i=y+1;
            if(Girl[i]>Girl[x-1]) Up++;
            else ans=max(ans,Up),Up=0;
        }
        else
        {
            if(Girl[i]>Girl[i-1]) Up++;
            else ans=max(ans,Up),Up=1;
        } 
    }    
    ans=max(ans,Up);
}
int main()
{
    T=read();
    while(T--)
    {
        ans=0;
        n=read();
        for(int i=1;i<=n;i++) Girl[i]=read();
        for(int i=0;i<=n;i++)
            for(int j=i;j<=n;j++) DeleteGirl(i,j);
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}