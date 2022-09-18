#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100000;
const int Maxm=200;
int t,n,m;
int sheep[Maxn];
int A[Maxm][Maxm];
inline int cmp(int a,int b){return a<b;}
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) scanf("%d",&sheep[i]);
        sort(sheep+1,sheep+1+m,cmp);
        sheep[0]=0,sheep[m+1]=n+1;
        for(int i=1;i<=m;i++)
        {
            for(int l=1;l<=m-i+1;l++)
            {
                int r=l+i-1;
                A[l][r]=0x3f3f3f3f;
                if(l==r) A[l][r]=sheep[r+1]-sheep[l-1]-2;
                else for(int k=l;k<=r;k++)
                {
                    A[l][r]=min(A[l][r],A[l][k-1]+A[k+1][r]+sheep[r+1]-sheep[l-1]-2);
                }
            }
        }
        printf("%d\n",A[1][m]);
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
2
8 1
3
20 3
3 6 14
*/