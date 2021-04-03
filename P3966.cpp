#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1000100;
int n,num=0;
string t;
int Trie[Maxn][30];
int Fail[Maxn];
int In[Maxn];
int WordTag[Maxn];
int Appear[Maxn];

inline void Insert(string s,int id)
{
    int root=0;
    for(int i=0;i<s.size();i++)
    {
        if(!Trie[root][s[i]-'a']) Trie[root][s[i]-'a']=++num;
        root=Trie[root][s[i]-'a'];
    }
    WordTag[id]=root;
    t+=s; t+='{';
}

void Make_Fail()
{
    queue<int> Q;
    for(int i=0;i<=26;i++) if(Trie[0][i]) Fail[Trie[0][i]]=0,Q.push(Trie[0][i]);
    while(!Q.empty())
    {
        int Now=Q.front(); Q.pop();
        for(int i=0;i<=26;i++)
        {
            if(Trie[Now][i])
            {
                Fail[Trie[Now][i]]=Trie[Fail[Now]][i];
                Q.push(Trie[Now][i]); In[Trie[Fail[Now]][i]]++;
            }
            else Trie[Now][i]=Trie[Fail[Now]][i];
        }
    }
}

void Query()
{
    int Now=0;
    for(int i=0;i<t.size();i++)
    {
        Now=Trie[Now][t[i]-'a'],Appear[Now]++;
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
        Appear[Fail[Now]]+=Appear[Now];
        if(!In[Fail[Now]]) Q.push(Fail[Now]);
    }
}

void Solve()
{
    string s;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>s,Insert(s,i);
    Make_Fail();
    Query(); Topu();
    for(int i=1;i<=n;i++) cout<<Appear[WordTag[i]]<<endl;
}
int main()
{
    Solve();
    system("pause");
    return 0;
}