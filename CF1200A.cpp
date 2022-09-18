#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char A[101001];
int state[20];
void Solve()
{
    scanf("%d",&n);
    scanf("%s",A+1);
    for(int i=1;i<=n;i++)
    {
        if(A[i]=='L')
        {
            for(int j=0;j<=9;j++) 
            {
                if(!state[j])
                {
                    state[j]=1; break ;
                }
            }
        }
        else if(A[i]=='R')
        {
            for(int j=9;j>=0;j--) 
            {
                if(!state[j])
                {
                    state[j]=1; break ;
                }
            }
        }
        else
        {
            int t=A[i]-'0'; state[t]=0;
        }
    }
    for(int i=0;i<=9;i++) printf("%d",state[i]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}