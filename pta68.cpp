#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int Maxn=1000001;
typedef long long ll;
string s;
ll A[Maxn][4];
int main()
{
    
    cin>>s;
    A[1][0]=A[1][1]=1,A[0][2]=A[0][3]=0;
    int n=s.length();
    for(int i=2;i<=n;i++)
    {
        A[i][0]=1;
        for(int j=1;j<=3;j++)
        {
            A[i][j]=A[i-1][j-1]+A[i-1][j];
            if(j==1&&s[i-1]==s[i-2]) A[i][j]-=1;
            else if(j==2&&s[i-1]==s[i-2]) A[i][j]-=A[i-2][1];
            else if(j==3&&s[i-1]==s[i-2]) A[i][j]-=A[i-2][2];
            if(j==2&&i>=3&&s[i-1]==s[i-3]&&s[i-1]!=s[i-2]) A[i][j]-=1;
            else if(j==3&&i>=3&&s[i-1]==s[i-3]&&s[i-1]!=s[i-2]) A[i][j]-=A[i-3][1];
            if(j==3&&i>=4&&s[i-1]==s[i-4]&&s[i-1]!=s[i-2]&&s[i-1]!=s[i-3]) A[i][j]-=1;
        }
    }
    cout<<A[n][0]+A[n][1]+A[n][2]+A[n][3]<<endl;
    system("pause");
    return 0;
}
