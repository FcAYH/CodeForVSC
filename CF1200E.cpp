#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxs=1000010;
int n,lenA=0;
char Ans[Maxs];
void Make_Next(char S[],int l)
{
    int Next[Maxs];
    int len=strlen(S+1),Nowp=0;
    for(int i=2;i<=len;i++)
    {
        while(Nowp&&S[Nowp+1]!=S[i]) Nowp=Next[Nowp];
        if(S[Nowp+1]==S[i]) Nowp++; Next[i]=Nowp;
    }
    for(int i=Next[len]+1;i<=l;i++) Ans[++lenA]=S[i];
}
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char S[Maxs];
        if(i==1)
        {
            scanf("%s",S+1);
            int sb=strlen(S+1);
            for(int j=1;j<=sb;j++) Ans[j]=S[j];
            lenA=strlen(S+1);
            continue ;
        }
        scanf("%s",S+1);
        int len1=strlen(S+1);
        int temp=len1;
        S[++temp]='%';
        if(lenA>len1) for(int i=lenA-len1+1;i<=lenA;i++) S[++temp]=Ans[i]; 
        else for(int i=1;i<=lenA;i++) S[++temp]=Ans[i];
        S[temp+1]=0;
        Make_Next(S,len1);
    }
    for(int i=1;i<=lenA;i++) printf("%c",Ans[i]);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}

/*
3
abb bba abba

3
abb bba aba

3
a b ab

Iwant to
tont

ease please
*/