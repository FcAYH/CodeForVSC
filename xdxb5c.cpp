#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100011;
const double Exp=0.0000001;
int n;
int vis[Maxn];
double x[Maxn];
double y[Maxn];
int Make1()
{
    memset(vis,0,sizeof(vis));
    double vecy1=(y[2]-y[1]),vecx1=(x[2]-x[1]);
    for(int i=3;i<=n;i++) 
    {
        double vecy2=(y[i]-y[2]),vecx2=(x[i]-x[2]);
        if(abs(vecx1*vecy2-vecx2*vecy1)>Exp) vis[i]=1;
    }
    int cnt=0,last=0;
    double vecx3=0,vecx4=0,vecy3=0,vecy4=0;
    for(int i=3;i<=n;i++)
    {
        if(vis[i]) 
        {
            cnt++;
            if(cnt==1) last=i,vis[i]=0;
            if(cnt==2) vecx3=(x[i]-x[last]),vecy3=y[i]-y[last],vis[i]=0,last=i;
            if(cnt>2) 
            {
                vecx4=(x[i]-x[last]),vecy4=(y[i]-y[last]);
                if(abs(vecx3*vecy4-vecx4*vecy3)<=Exp) vis[i]=0; 
            }
        }
    }
    for(int i=1;i<=n;i++) if(vis[i]) return 0;
    return 1;
}
int Make2()
{
    memset(vis,0,sizeof(vis));
    double vecx1=(x[3]-x[1]),vecy1=(y[3]-y[1]);
    for(int i=2;i<=n;i++) 
    {
        double vecy2=(y[i]-y[3]),vecx2=(x[i]-x[3]);
        if(abs(vecx1*vecy2-vecx2*vecy1)>Exp) vis[i]=1;
    }
    int cnt=0,last=2;
    double vecx3=0,vecx4=0,vecy3=0,vecy4=0;
    vis[2]=0;
    for(int i=4;i<=n;i++)
    {
        if(vis[i])
        {
            cnt++;
            if(cnt==1) vecx3=(x[i]-x[last]),vecy3=(y[i]-y[last]),vis[i]=0,last=i;
            if(cnt>1) 
            {
                vecx4=(x[i]-x[last]),vecy4=(y[i]-y[last]);
                if(abs(vecx3*vecy4-vecx4*vecy3)<=Exp) vis[i]=0; 
            }
        } 
    }
    for(int i=1;i<=n;i++) if(vis[i]) return 0;
    return 1;
}
int Make3()
{
    memset(vis,0,sizeof(vis));
    double vecx1=(x[3]-x[2]),vecy1=(y[3]-y[2]);
    for(int i=2;i<=n;i++) 
    {
        double vecy2=(y[i]-y[3]),vecx2=(x[i]-x[3]);
        if(abs(vecx1*vecy2-vecx2*vecy1)>Exp) vis[i]=1;
    }
    int cnt=0,last=1;
    vis[1]=0;
    double vecx3=0,vecx4=0,vecy3=0,vecy4=0;
    for(int i=4;i<=n;i++)
    {
        if(vis[i])
        {
            cnt++;
            if(cnt==1) vecx3=(x[i]-x[last]),vecy3=(y[i]-y[last]),vis[i]=0,last=i;
            if(cnt>1) 
            {
                vecx4=(x[i]-x[last]),vecy4=(y[i]-y[last]);
                if(abs(vecx3*vecy4-vecx4*vecy3)<=Exp) vis[i]=0; 
            }
        } 
    }
    for(int i=1;i<=n;i++) if(vis[i]) return 0;
    return 1;
}
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
    if(Make1()) printf("YES");
    else if(Make2()) printf("YES");
    else if(Make3()) printf("YES");
    else printf("NO");

}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
5
0 0
0 1
1 1
1 -1
2 2
*/