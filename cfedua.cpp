#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int Maxn=200;
const int Maxm=1000;
int t,len1,len2;
char s1[Maxm],h[Maxm];
int vis[Maxn],vis2[Maxn];
void Print()
{
    for(int i=97;i<=122;i++) printf("%d %d\n",vis[i],vis2[i]);
}
inline int Check(int x)
{
    memset(vis2,0,sizeof(vis2));
    for(int i=x;i<=x+len1-1;i++) vis2[(int)h[i]]++;
    //Print();
    for(int i=97;i<=122;i++) if(vis2[i]!=vis[i]) return 0;
    return 1;
}
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cin>>(s1+1)>>(h+1);
        len1=strlen(s1+1),len2=strlen(h+1);
        for(int i=1;i<=len1;i++) vis[(int)s1[i]]++;
        int flag=0;
        for(int i=1;i<=len2;i++)
        {
            if(i+len1-1>len2) break ;
            if(Check(i))
            {
                flag=1;
                printf("YES\n"); break ;
            }
        }
        if(!flag) printf("NO\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}