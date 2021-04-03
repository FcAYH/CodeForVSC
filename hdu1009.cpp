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
const double eps=0.00000001;
stack <int> sta;
bool vis[505050];
double t[505050];
struct pro
{
    double p,a;
}s[505050];

int read()
{
    int rt = 0, in = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') in = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {rt = rt * 10 + ch - '0'; ch = getchar();}
    return rt * in;
}
bool cmp(pro a, pro b)
{
    if(a.p == b.p)  return a.a > b.a;
    else    return a.p > b.p;
}
int main()
{
    int T = read();
    while(T--)
    {
        int n = read(), cnt = 0, ans = 0;
        for(int i = 1; i <= n; i++) vis[i] = 0, scanf("%lf%lf", &s[i].p, &s[i].a);
        sort(s+1, s+1+n, cmp);
        double as = 0;
        for(int i = 1; i <= n; i++)
            if(s[i].a > as)
            {
                s[++cnt] = s[i];
                as = s[i].a;
                if(s[i].a == s[i+1].a && s[i].p == s[i+1].p)    vis[i] = 1;
            }
        if(cnt == 0)
        {
            printf("0\n");
            continue;
        }
        sta.push(1);
        t[1] = 0;
        for(int i = 2; i <= cnt; i++)
        {
            int x = sta.top();
            double t1 = sqrt(2*(s[x].p - s[i].p) / (s[i].a - s[x].a));
            while(t1 < t[sta.top()]+eps)  
            {
                sta.pop();
                x = sta.top();
                t1 = sqrt(2*(s[x].p - s[i].p) / (s[i].a - s[x].a));
            }
            t[i] = t1;
            sta.push(i);
        }
        while(!sta.empty())
        {
            int x = sta.top();
            if(!vis[x]) ans++;
            sta.pop();
        }
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}