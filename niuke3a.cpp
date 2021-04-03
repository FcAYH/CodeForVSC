#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=2000001;
int t,n;
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
inline void Greedy(string s)
{
    int Empty[Maxn];
    int feed=0,ans=0,cnt=0;
    for(int i=s.size();i>=0;i--)
    {
        if(s[i]=='0'||s[i]=='1') cnt++;
        if(s[i]=='1') Empty[i]=cnt;
    }
    for(int i=0;i<s.size();i++)
    {
        switch(s[i])
        {
            case '0':
            {
                if(feed) ans++,feed--;
                break ;
            }
            case '1':
            {
                if(Empty[i]>feed) feed++;
                else if(feed) ans++,feed--;
                else feed++;
                break ;
            }
            case '2':
            {
                ans++;
                break ;
            }
            case '3':
            {
                ans++;
                break ;
            }
        }
    }
    printf("%d\n",ans);
}

void Solve()
{
    t=read();
    while(t--)
    {
        string s;
        n=read();cin>>s;
        Greedy(s);
        //printf("%d\n",)
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
10
4 1100
5 22332
10 2233211012


*/