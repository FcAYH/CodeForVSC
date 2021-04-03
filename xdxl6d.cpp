#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=5000010;
int t,n,p,q,m;
ll ans=0;
int vis[Maxn];
unsigned int SA,SB,SC;
unsigned int rng61()
{
    SA^=SA<<16;
    SA^=SA>>5;
    SA^=SA<<1;
    unsigned int t=SA;
    SA=SB;
    SB=SC,
    SC^=t^SA;
    return SC;
}
void gen()
{
    stack<ll> st,dst,id_st,id_dst;
    ll last,st_top,dst_top;
    scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
    for(int i=1;i<=n;i++)
    {
        if(rng61()%(p+q)<p) 
        {
            st.push(rng61()%m+1),id_st.push(i);
            if(dst.empty()) dst.push(st.top()),id_dst.push(id_st.top());
            else if(st.top()>dst.top()) dst.push(st.top()),id_dst.push(id_st.top());
            ans^=(ll)i*dst.top();
        }
        else 
        {
            if(!st.empty()) 
            {
                int st_top=st.top(),st_id=id_st.top();
                st.pop(),id_st.pop();
                vis[st_id]=1;
                while(!dst.empty()&&vis[id_dst.top()]) id_dst.pop(),dst.pop();
                if(!dst.empty())ans^=(ll)i*dst.top();
            }
        }
    }
}
/*
void gen()
{
    stack<ll> st,dst;
    ll last,st_top,dst_top;
    scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
    for(int i=1;i<=n;i++)
    {
        int flag=1;
        if(dst.empty()) dst.push(0);
        if(rng61()%(p+q)<p) st.push(rng61()%m+1);
        else if(st.size()) last=st.top(),st.pop(),flag=0;
        if(st.empty())
        {
            while(dst.size()) dst.pop();
            dst.push(0);
        }
        else 
        {
            st_top=st.top(),dst_top=dst.top();
            if(flag) if(st_top>=dst_top) dst.push(st_top);
            else if(last>=dst_top&&dst.size()) dst.pop();
            if(dst.empty()) dst.push(0);
            ans^=(ll)i*dst.top();
        }
    }
}
*/
void Solve()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        memset(vis,0,sizeof(vis));
        ans=0ll;
        gen();
        printf("Case #%d: %lld\n",i,ans);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
POP();
POP();
PUSH(1);
PUSH(4).
*/