#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=2000010;
int n,num=0;
string s[Maxn];
int Trie[Maxn][27];
int WordTag[Maxn];
int Fail[Maxn];
int In[Maxn];
int Apear[Maxn];

inline void Insert(string S,int id)
{
    int root=0;
    for(int i=0;i<S.size();i++)
    {
        if(!Trie[root][S[i]-'a']) Trie[root][S[i]-'a']=++num;
        root=Trie[root][S[i]-'a'];
    }
    WordTag[id]=root;
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
                Q.push(Trie[Now][i]); In[Fail[Trie[Now][i]]]++;
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
        Apear[Now]++;
    }
}

void Topu()
{
    queue<int> Q;
    for(int i=1;i<=num;i++) if(!In[i]) Q.push(i);
    while(!Q.empty())
    {
        int Now=Q.front(); Q.pop();
        In[Fail[Now]]--;
        Apear[Fail[Now]]+=Apear[Now];
        if(!In[Fail[Now]]) Q.push(Fail[Now]);
    } 
}

void Solve()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i],Insert(s[i],i);
    Make_Fail();
    string t;
    cin>>t;
    Query(t); Topu();
    for(int i=1;i<=n;i++) cout<<Apear[WordTag[i]]<<endl;
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
6
a
a
bb
aa
abaa
abaaa
abaaabaa
*/