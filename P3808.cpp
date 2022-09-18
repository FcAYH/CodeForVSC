#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
const int Maxn = 1000100;
int n,cnt=0;
int trie[Maxn][30], fail[Maxn], rt[Maxn];

void Insert(string st)
{
	int k = 0;
	for(int i = 0; i < st.size(); i++)
	{
		int c = st[i] - 'a';
		if(!trie[k][c])	trie[k][c] = ++cnt;
		k = trie[k][c];
	}
	rt[k]++;
}

void Set_fail()
{
	queue <int> q;
	for(int i = 0; i < 26; i++)	if(trie[0][i]) fail[trie[0][i]] = 0, q.push(trie[0][i]);
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		for(int i = 0; i < 26; i++)
        {
			if(trie[k][i])
			{
				fail[trie[k][i]] = trie[fail[k]][i];
				q.push(trie[k][i]);
			}
			else	trie[k][i] = trie[fail[k]][i];
        }
    }
}

int Query(string st)
{
	int k = 0, ans = 0;
	for(int i = 0; i < st.size(); i++)
	{
		k = trie[k][st[i]-'a'];
		for(int j = k; j&&rt[j]!=-1; j = fail[j])
			ans += rt[j], rt[j] = -1; 
	}
	return ans;
}
string t;
int main()
{
    freopen("P3808_2.in","r",stdin);
    freopen("P3808_2.out","w",stdout);
	scanf("%d",&n);
	
	for(int i = 1; i <= n; i++)
	{
        cin>>t;

		Insert(t);
	}
    Set_fail();
	cin>>t;
    //scanf("%s",t);
	//t[strlen(t)] = 0;
    
	printf("%d",Query(t));
    //system("pause");
	return 0;
}