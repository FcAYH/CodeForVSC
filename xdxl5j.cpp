#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Inf=0x3f3f3f3f;
const int Maxn=1000;
int n;
int A[Maxn][Maxn];
char s[Maxn];

inline int check(int left,int len,int right)
{
    for(int i=left;i<=right-len;i++) if(s[i]!=s[i+len]) return 0;
    return 1;
}
void Dynamic_P()
{
    memset(A,0x3f,sizeof(A));
    for(int i=1;i<=n;i++) A[i][i]=1;
    for(int len=2;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            for(int k=l;k<r;k++) A[l][r]=min(A[l][r],A[l][k]+A[k+1][r]);
            for(int k=1;k<=len;k++)
            {
                if(!(len%k)&&check(l,k,r)) A[l][r]=min(A[l][r],A[l][l+k-1]);
            }
        }
    }
    //for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) printf("%d %d %d \n",i,j,A[i][j]);
    printf("%d",A[1][n]);
}
void Solve()
{
    scanf("%d",&n);
    cin>>(s+1);
    Dynamic_P();
}
int main()
{
    Solve();
    system("pause");
    return 0;
}