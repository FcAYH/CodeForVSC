#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=5550;
const ll Inf=0x7fffffffffffff;
int n,w,s;
ll a[Maxn];
struct Queue{ll v;int id;}Q[Maxn*2];
ll A[Maxn][Maxn];
ll ans=-Inf;
inline ll read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{ 
    for(int i=0;i<=5500;i++) for(int j=0;j<=5500;j++) A[i][j]=-Inf;
    scanf("%d%d%d",&n,&w,&s);
    for(int i=1;i<=n;i++) a[i]=read();
    A[1][1]=a[1];
    for(int i=2;i<=n;i++)
    {
        int nowp=min(i,w);
        int head=1,tail=0;
        Q[++tail].v=A[i-1][nowp],Q[tail].id=nowp;
        while(head<=tail&&A[i-1][nowp-1]>=Q[tail].v) tail--;
        while(head<=tail&&Q[head].id>nowp+s-1) head++;
        Q[++tail].v=A[i-1][nowp-1],Q[tail].id=nowp-1;
        A[i][nowp]=Q[head].v+a[i]*(ll)nowp;
        for(int j=nowp-1;j>=1;j--)
        {
            if(j!=1) while(head<=tail&&A[i-1][j-1]>=Q[tail].v) tail--;
            while(head<=tail&&Q[head].id>j+s-1) head++;
            if(j!=1) Q[++tail].v=A[i-1][j-1],Q[tail].id=j-1;
            A[i][j]=Q[head].v+a[i]*(ll)j;
        }
    }
    for(int i=1;i<=w;i++) ans=max(ans,A[n][i]);
    printf("%lld",ans);
}
int main()
{
    freopen("P5858_22.in","r",stdin);
    freopen("P5858_22.out","w",stdout);
    Solve();
    //system("pause");
    return 0;
}
/*
5 3 1
-1 -3 -2 -4 -5
*/