#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
const int Inf=0x3f3f3f3f;
const int Maxn=2000010;
int n,m,k;
int cnt=0;
int vis[Maxn];
struct Clothes{int v,id;}A[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline int cmp(Clothes a,Clothes b){return (a.v==b.v)?a.id<b.id:a.v<b.v;}
void Solve()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++)
    {
        k=read();
        for(int j=1;j<=k;j++) A[++cnt].v=read(),A[cnt].id=i;
    }
    sort(A+1,A+1+cnt,cmp);
    int p1=1,p2=1;
    int num=0;
    int ans=Inf;
    while(p2<=cnt)
    {
        //printf("%d %d\n",p1,p2);
        if(!vis[A[p2].id]) num++; vis[A[p2].id]++;
       
        if(num==m)
        {
            ans=min(ans,A[p2].v-A[p1].v);
        }
        while(num>m&&p1<p2) 
        {
            //printf("%d ",A[p1].id);
            vis[A[p1].id]--;
            if(!vis[A[p1].id]) num--;
            p1++;
        }
        if(num==m)
        {
            ans=min(ans,A[p2].v-A[p1].v);
        }
        p2++;
    }
    printf("%d\n",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}