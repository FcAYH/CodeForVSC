#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=300;
int t,n;
int a[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline int cmp(int a,int b){return a<b;}
void Solve()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        if(n<10||n>13) 
        {
            printf("No\n"); continue ;
        }
        sort(a+1,a+1+n,cmp);
        if(a[1]!=a[2]) 
        {
            printf("No\n"); continue ;
        }
        if(a[1]!=1) 
        {
            printf("No\n"); continue ;
        }
        if(a[n]==a[n-1])
        {
            printf("No\n"); continue ;
        }
        int flag=0;
        for(int i=3;i<n;i++) 
        {
            if(a[i]-a[i-1]>2) 
            {
                flag=1;
                printf("No\n"); break ;
            }
        }
        if(!flag) printf("Yes\n");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
8
9
1 2 3 4 5 6 7 8 9
10
1 2 3 4 5 6 7 8 9 10
11
999 1 1 2 3 4 5 6 7 8 9
11
999 1 3 5 7 9 11 13 17 19 21
10
15 1 13 17 1 7 9 5 3 11
13
1 1 1 1 1 1 1 1 1 1 1 1 2
10
2 3 4 5 6 7 8 9 10 11
10
15 1 13 3 6 5 4 7 1 14
*/