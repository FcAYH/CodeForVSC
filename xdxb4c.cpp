#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=200;
int t,n;
char s[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>(s+1);
        int left=1;
        while(s[left]=='<') left++;
        int right=n;
        while(s[right]=='>') right--;
        int ans1=left-1,ans2=n-right;
        printf("%d\n",min(ans1,ans2));
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}