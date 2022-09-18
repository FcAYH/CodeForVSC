#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100001;
const int Maxm=100001;
const int MaxT=400004;
const int MaxEDGE=300001;
int numEDGE=0,num=0,cnt=0;

int Fa[Maxn];
int Trie[Maxn][27];
int Fail[Maxn];
int head[Maxn];
int dfn[Maxn];
int low[Maxn];
int WordTag[Maxn];
int T[MaxT+10];
struct Query
{
    int x,y,id,ans;
}Q[Maxm];
struct EDGE{int next,to;}E[MaxEDGE];

inline void add_edge(int x,int y)
{
    E[++numEDGE].next=head[x],E[numEDGE].to=y,head[x]=numEDGE;
    E[++numEDGE].next=head[y],E[numEDGE].to=x,head[y]=numEDGE;
}

inline void Insert(int x,int y)
{
    while(x<=MaxT) T[x]+=y,x+=x&(-x);
}

inline int Search(int x)
{
    int ret=0;
    while(x) ret+=T[x],x-=x&(-x);
    return ret;
}

void Build_Trie(string s)
{
    int root=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='B') root=Fa[root];
        else if(s[i]=='P') WordTag[++cnt]=root;
        else
        {
            if(!Trie[root][s[i]-'a']) Trie[root][s[i]-'a']=++num,Fa[num]=root;
            root=Trie[root][s[i]-'a']; 
        }    
    }
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
    for(int i=1;i<=num;i++) add_edge(i,Fail[i]);
}

int dfncnt=0;
void Dfs_FailTree(int poi,int fa)
{
    dfn[poi]=++dfncnt;
    for(int i=head[poi];i;i=E[i].next)
    {
        int qt=E[i].to;
        if(qt!=fa) Dfs_FailTree(qt,poi);
    }
    low[poi]=dfncnt;
}

void Make_Ans(string s)
{
    int root=0,cntq=0,Nowq=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='B') 
        {
            Insert(dfn[root],-1);
            root=Fa[root];
        }
        else if(s[i]=='P') 
        {
            ++cntq;
            while(Q[Nowq].y==cntq)
            {
                Q[Nowq].ans=Search(low[WordTag[Q[Nowq].x]])-Search(dfn[WordTag[Q[Nowq].x]]-1);
                Nowq++;
            }
        }
        else
        {
            
            root=Trie[root][s[i]-'a'];
            Insert(dfn[root],1);
        }
    }
}
inline int y_cmp(Query a,Query b){return (a.y==b.y)?a.x<b.x:a.y<b.y;}
inline int id_cmp(Query a,Query b){return a.id<b.id;}
void Solve()
{
    ios::sync_with_stdio(false);
    string s;
    int m;
    cin>>s;
    Build_Trie(s);
    Make_Fail();
    Dfs_FailTree(0,0);
    cin>>m;
    for(int i=1;i<=m;i++) cin>>Q[i].x>>Q[i].y,Q[i].id=i;
    sort(Q+1,Q+1+m,y_cmp);
    Make_Ans(s);
    sort(Q+1,Q+1+m,id_cmp);
    for(int i=1;i<=m;i++) printf("%d\n",Q[i].ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
aPaPBbPaPBBBbaPaPBBbPaP
44
8 8
7 7
5 5
7 8
1 6
8 8
1 8
4 4
7 8
5 8
1 5
3 4
1 5
7 7
5 6
1 2
2 2
5 6
1 4
1 1
1 4
2 6
3 3
1 3
1 6
1 1
1 8
2 6
1 8
1 2
1 4
1 2
5 8
2 2
1 1
2 2
5 8
7 8
5 5
1 6
7 7
6 6
3 4
1 4
*/