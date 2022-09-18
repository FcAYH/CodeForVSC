#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Inf=0x3f3f3f3f;
const int Maxn=40;
struct SPORT{string name;int sco;}Spo[Maxn];
int n,k;
int score[Maxn];
inline int cmp(SPORT a,SPORT b){return a.sco>b.sco;}
void Solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>Spo[i].name;
        int sum=0;
        for(int j=1;j<=k;j++) cin>>score[j],sum+=score[j];
        int Max=-Inf,Min=Inf;
        for(int j=1;j<=k;j++) Max=max(Max,score[j]),Min=min(Min,score[j]);
        Spo[i].sco=sum-Max-Min;
    }
    sort(Spo+1,Spo+1+n,cmp);
    cout<<Spo[1].name<<" "<<Spo[2].name<<endl;
}
int main()
{
    Solve();
    return 0;
}