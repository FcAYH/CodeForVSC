#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxs=155;
const int Maxn=1000010;
int n,num=0;
string s[Maxs];
int Trie[Maxn][27];
int WordTag[Maxn];
int Fail[Maxn];
int Apear[Maxs];

inline void Array_Ini()
{
    num=0;
    memset(Trie,0,sizeof(Trie));
    memset(WordTag,0,sizeof(WordTag));
    memset(Apear,0,sizeof(Apear));
}

inline void Insert(string S,int id)
{
    int root=0;
    for(int i=0;i<S.size();i++)
    {
        if(!Trie[root][S[i]-'a']) Trie[root][S[i]-'a']=++num;
        root=Trie[root][S[i]-'a'];
    }
    WordTag[root]=id;
}

void Make_Fail()
{
    queue<int> Q;
    for(int i=0;i<26;i++) if(Trie[0][i]) Fail[Trie[0][i]]=0,Q.push(Trie[0][i]);
    while(!Q.empty())
    {
        int Now=Q.front(); Q.pop();
        for(int i=0;i<26;i++)
        {
            if(Trie[Now][i])
            {
                Fail[Trie[Now][i]]=Trie[Fail[Now]][i];
                Q.push(Trie[Now][i]);
            }
            else Trie[Now][i]=Trie[Fail[Now]][i];
        }
    }
}

void Query(string t)
{
    int Now=0;
    for(int i=0;i<t.size();i++)
    {
        Now=Trie[Now][t[i]-'a'];
        for(int j=Now;j;j=Fail[j])
        {
            if(WordTag[j]) Apear[WordTag[j]]++;
        }
    }
}

void Solve()
{
    ios::sync_with_stdio(false);
    cin>>n;
    while(n)
    {
        Array_Ini();
        for(int i=1;i<=n;i++) cin>>s[i],Insert(s[i],i);
        Make_Fail();
        string t;
        cin>>t;
        Query(t);
        int Max=-1;
        for(int i=1;i<=n;i++) Max=max(Max,Apear[i]);
        cout<<Max<<endl;
        for(int i=1;i<=n;i++) if(Apear[i]==Max) cout<<s[i]<<endl;
        cin>>n; 
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}