#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;
int n, k, cnt[60];
long long ans;
struct pro
{
    int a, b, c, d;
}s[60][60];
int read()
{
    int rt = 0, in = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') in = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {rt = rt * 10 + ch - '0'; ch = getchar();}
    return rt * in;
}
inline int cmp(pro a,pro b){return (a.a)*(a.b)*(a.c)*(a.d)>(b.a)*(b.b)*(b.c)*(b.d);}
int main()
{
    int T = read();
    while(T--)
    {
        ans = 0;
        memset(s, 0, sizeof(s));
        memset(cnt, 0, sizeof(cnt));
        n = read(), k = read();
        for(int i = 1; i <= n; i++)
        {
            int x = read();
            ++cnt[x];
            s[x][cnt[x]].a = read();
            s[x][cnt[x]].b = read();
            s[x][cnt[x]].c = read();
            s[x][cnt[x]].d = read();
        }
        for(int i=1;i<=k;i++)
        {
            sort(s[i]+1,s[i]+1+cnt[i],cmp);
        }
        long long suma=0ll,sumb=0ll,sumc=0ll,sumd=0ll;
        for(int i=1;i<=k;i++)
        {
            suma+=s[i][1].a,sumb+=s[i][1].b,sumc+=s[i][1].c,sumd+=s[i][1].d;
        }
        printf("%lld\n",(100ll+suma)*(100ll+sumb)*(100ll+sumc)*(100ll+sumd));
    }
    system("pause");
    return 0;
}