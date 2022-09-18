#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}

string number[3];
string shape[3];
string shading[3];
string color[3];
int n,t;
char s[100];
void Solve()
{
    number[0]="one",number[1]="two",number[2]="three";
    shape[0]="diamond",shape[1]="squiggle",shape[2]='oval';
    shading[0]="solid",shading[1]="striped",shading[2]="open";
    color[0]="red",color[1]="green",color[2]="purple";
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;i++)
        {
            cin>>(s+1);
            int a,b,c,d;
            int len=strlen(s+1);
            int cnt=1,j=1;
            while(j<=len)
            {
                if(s[j]=='[')
                {
                    string temp;
                    j++;
                    while(s[j]!=']') temp+=s[j],j++;
                    if(cnt==1) 
                    {
                        if(temp=="*") a=3;
                        for(int j=0;j<=2;j++) if(temp==number[j]) a=j;
                    }
                    if(cnt==2)
                    {
                        if(temp=="*") b=3;
                        for(int j=0;j<=2;j++) if(temp==shape[j]) b=j;
                    }
                    if(cnt==3)
                    {
                        if(temp=="*") c=3;
                        for(int j=0;j<=2;j++) if(temp==shading[j]) c=j;
                    }
                    if(cnt==4)
                    {
                        if(temp=="*") d=3;
                        for(int j=0;j<=2;j++) if(temp==color[j]) d=j;
                    }
                    cnt++;
                }
                j++;
            }
            printf("%d %d %d %d \n",a,b,c,d);
        }
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}