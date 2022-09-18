#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Inf=0x3f3f3f3f;
const int Maxn=300000;
int t,n,Gap=0;
int A[Maxn];

struct Jam{int id,v;}G[Maxn]; 
inline void Ini()
{
    G[n].id=n;
    G[n].v=(A[n]==1?-1:1);
    for(int i=n-1;i>=1;i--) 
    {
        G[i].id=i,
        G[i].v=(A[i]==1?G[i+1].v-1:G[i+1].v+1);
    }
    G[n+1].id=n+1;
    G[n+1].v=(A[n+1]==1?-1:1);
    for(int i=n+2;i<=2*n;i++)
    {
        G[i].id=i;
        G[i].v=(A[i]==1?G[i-1].v-1:G[i-1].v+1);
    }
}
inline int cmp(Jam a,Jam b){return (a.v==b.v)?(a.id<b.id):(a.v<b.v);}
void Binary_search()
{
    int ans=Inf;
    for(int i=n;i>=1;i--) if(G[i].v==-Gap){ans=n-i+1; break ;}
    for(int i=n+1;i<=n+n;i++) if(G[i].v==-Gap){ans=min(ans,i-n); break ;}
    //sort(G+1,G+1+n,cmp);
    sort(G+n+1,G+1+n+n,cmp); 
    for(int i=n;i>=1;i--)
    {
        int nowg=G[i].v;
        int targ=-(Gap+nowg);
        int l=n+1,r=n+n;
        //ans=min(ans,(int)(lower_bound(G+n+1,G+n+n,(0,targ))-G-i+1));
        
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(G[mid].v==targ) 
            {
                //cout<<i<<endl;
                ans=min(ans,G[mid].id-i+1);
                r=mid-1;
            }
            else if(G[mid].v>targ) r=mid-1;
            else l=mid+1;
        }
        
    }
    printf("%d\n",ans);
}
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        Gap=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&A[i]);
        for(int i=1;i<=n;i++) scanf("%d",&A[i+n]);
        for(int i=1;i<=2*n;i++) (A[i]==1)?Gap++:Gap--;
        
        if(!Gap) 
        {
            printf("0\n"); continue ;
        }
        Ini();
        Binary_search();
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
1311312
10
1 1 1 1 1 2 2 2 2 1             1 1 2 2 2 2 1 1 1 1
*/