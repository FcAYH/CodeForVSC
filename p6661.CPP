#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100010;
int t,k;
char A[Maxn],B[Maxn];
int a[Maxn],b[Maxn];
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s%d",A+1,B+1,&k);
        int len=strlen(A+1);
        for(int i=1;i<=len;i++) a[i]=A[i]-'0',b[i]=B[i]-'0';
        int cnt=0,Tar=-1;
        for(int i=1;i<=len;i++)
        {
            if(b[i])
            {
                int nowc=0;
                if(a[i]>=b[i])
                {
                    nowc=cnt+1;
                    if(nowc<=k&&nowc+len-i>=k) Tar=i;
                }
                else 
                {
                    if(b[i]>1)
                    {
                        nowc=cnt;
                        if(nowc<=k&&nowc+len-i+1>=k) Tar=i;
                    }
                    else
                    {
                        nowc=cnt;
                        if(nowc<=k&&nowc+len-i>=k) Tar=i;
                    }
                    
                }
            }
            if(a[i]!=b[i]) cnt++;
        }

        if(Tar==-1){printf("-1\n"); continue ;}
        
        cnt=0;
        for(int i=1;i<=Tar-1;i++) if(a[i]!=b[i]) cnt++,a[i]=b[i];
        
        if(a[Tar]>=b[Tar]) cnt++,a[Tar]=b[Tar]-1;
        else if(cnt<k&&a[Tar]!=b[Tar]-1) cnt++,a[Tar]=b[Tar]-1;
        
        if(cnt<k)
        {
            for(int i=Tar+1;i<=len;i++) if(A[i]!='9'&&cnt<k) cnt++,a[i]=9;
        }
        if(cnt<k)
        {
            for(int i=len;i>=Tar+1;i--) if(A[i]=='9'&&cnt<k) cnt++,a[i]=8;
        }
        
        if(cnt==k-1) cnt++,a[Tar]--;
        for(int i=1;i<=len;i++) printf("%d",a[i]); puts("");
    }
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}
