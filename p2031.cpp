#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=600;
int n;
char s[Maxn];
int len[Maxn];
char dic[Maxn][Maxn];
int vis[Maxn][Maxn];
int A[Maxn];
inline int Check(int st,int ed,int k)
{
    if(len[k]>ed-st+1) return 0; 
    for(int i=st;i<=st+len[k]-1;i++) if(s[i]!=dic[k][i-st+1]) return 0;
    return 1;
}
void Solve()
{
    scanf("%s",s+1);
    int length=strlen(s+1);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",dic[i]+1);
    for(int i=1;i<=n;i++) len[i]=strlen(dic[i]+1);
    for(int i=length;i>=1;i--)
    {
        for(int j=i;j>=1;j--)
        {
            if(vis[j+1][i]){vis[j][i]=1; continue ;}
            else for(int k=1;k<=n;k++) if(Check(j,i,k)) vis[j][i]=1;
        }
    }
    /*
    for(int i=1;i<=length;i++)
        for(int j=i+1;j<=length;j++) printf("%d %d %d\n",i,j,vis[i][j]);
    */
    for(int i=1;i<=length;i++) if(vis[1][i]){A[i]=1; break ;}
    for(int i=1;i<=length;i++)
    {
        for(int j=i;j>1;j--) A[i]=max(A[i],A[j-1]+vis[j][i]);
    }
    //for(int i=1;i<=length;i++) printf("%d ",A[i]);
    printf("%d",A[length]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
abaab
1
ab
*/