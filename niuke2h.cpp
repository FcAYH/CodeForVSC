#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstring>
const int Max = 2e6;
struct Key
{
	int key1,key2;
	bool operator<(const Key a)const
    {
		if(key1 == a.key1)
			return key2 < a.key2;
		return key1 < a.key1;
	}
	bool operator==(const Key a)const
    {
		return key1 == a.key1 && key2 == a.key2;
	}
	bool operator>(const Key a)const
    {
		if(key1 == a.key1)  return key2 > a.key2;
		return key1 > a.key1;
	}
	Key(int x = 0, int y =0)
    {
		key1 = x, key2 = y;
	}
};

class Splay_Tree_Type
{
    private:
        struct Tree_Date
        {
            int weigth;
            int size;
            Key key;
            int child[2];
            int father;
            int Min;
        }tree[Max];
        
        inline int Get_Son (int now)
        {
            return tree[tree[now].father].child[1] == now;
        }
        int Count;
        int Root;
    public :
        inline void Update (int now)
        {
            tree[now].size = tree[now].weigth;
            tree[now].Min=tree[now].key.key2;
            if (tree[now].child[0])
            {
                tree[now].size += tree[tree[now].child[0]].size;
                tree[now].Min = std::min(tree[now].Min,tree[tree[now].child[0]].Min);
            }
            if (tree[now].child[1]){
                tree[now].size += tree[tree[now].child[1]].size;
                tree[now].Min=std::min(tree[now].Min,tree[tree[now].child[1]].Min);
            }
        }
        
        inline void Rotate (int now)
        {
            int father = tree[now].father;
            int Grand = tree[father].father;
            int pos = Get_Son (now);
            tree[father].child[pos] = tree[now].child[pos ^ 1];
            tree[tree[father].child[pos]].father = father;
            tree[now].child[pos ^ 1] = father;
            tree[father].father = now;
            tree[now].father = Grand;
            if (Grand)
                tree[Grand].child[tree[Grand].child[1] == father] = now;
            Update (father);
            Update (now);
        }
        
        inline void Splay (int now)
        {
            for (int father; father = tree[now].father; Rotate (now))
                if (tree[father].father)
                    Rotate (Get_Son (now) == Get_Son (father) ? father : now);
            Root = now;
        }
        
        inline int Find_Prefix ()
        {
            int now = tree[Root].child[0];
            while (tree[now].child[1])
                now = tree[now].child[1];
            return now;
        }
        inline int Find_Suffix ()
        {
            int now = tree[Root].child[1];
            while (tree[now].child[0])
                now = tree[now].child[0];
            return now;
        }
        
        inline void Clear (int now)
        {
            tree[now].child[1] = 0;
            tree[now].child[1] = 1;
            tree[now].size = 0;
            tree[now].weigth = 0;
            tree[now].key.key1= 0;
            tree[now].key.key2=0;
            tree[now].father = 0;
        }
        
        inline int Find_x_rank (Key x)
        {
            int now = Root;
            int Answer = 0;
            while (true)
            {
                if (x < tree[now].key)
                {
                    now = tree[now].child[0];
                    continue;
                }
                Answer += tree[now].child[0] ? tree[tree[now].child[0]].size : 0;
                if (tree[now].key == x)
                {
                    Splay (now);
                    return Answer + 1;
                }
                Answer += tree[now].weigth;
                now = tree[now].child[1];
            }
        }
        
        inline Key Find_rank_x (int x)
        {
            int now = Root;
            while (true)
            {
                if (tree[now].child[0] && x <= tree[tree[now].child[0]].size)
                {
                    now = tree[now].child[0];
                    continue;
                }
                int temp = (tree[now].child[0] ? tree[tree[now].child[0]].size : 0) + tree[now].weigth;
                if (x <= temp)
                    return tree[now].key;
                x -= temp;
                now = tree[now].child[1];
            }
        }
        
        inline void Insert (Key x)
        {
            if (!Root)
            {
                Count++;
                tree[Count].key = x;
                tree[Count].size = 1;
                tree[Count].weigth = 1;
                tree[Count].Min=x.key2;
                Root = Count;
                return;
            }
            int father = 0, now = Root;
            while (true)
            {
                if (tree[now].key == x)
                {
                    tree[now].size++;
                    tree[now].weigth++;
                    Splay (now);
                    return ;
                }
                father = now;
                now = tree[now].child[x > tree[father].key];
                if (!now)
                {
                    Count++;
                    tree[father].child[x > tree[father].key] = Count;
                    tree[Count].father = father;
                    tree[Count].key = x;
                    tree[Count].size = 1;
                    tree[Count].weigth = 1;
                    Splay (Count);
                    return ;
                }
            }
        }
        
        inline void Delete (Key x)
        {
            Find_x_rank (x);
            if (tree[Root].weigth > 1)
            {
                tree[Root].weigth--;
                tree[Root].size--;
                return ;
            }
            if (!tree[Root].child[0] && !tree[Root].child[1])
            {
                Clear (Root);
                Root = 0;
                return ;
            }
            if (!tree[Root].child[0])
            {
                int temp = Root;
                Root = tree[Root].child[1];
                tree[Root].father = 0;
                Clear (temp);
                return ;
            }
            if (!tree[Root].child[1])
            {
                int temp = Root;
                Root = tree[Root].child[0];
                tree[Root].father = 0;
                Clear (temp);
                return ;
            }
            int Prefix = Find_Prefix ();
            int temp = Root;
            Splay (Prefix);
            tree[Root].child[1] = tree[temp].child[1];
            tree[tree[temp].child[1]].father = Root;
            Clear (temp);
            Update (Root);
        }
        
        inline Key Get_tree_value (int now)
        {
            return tree[now].key;
        }
        
        inline int sol()
        {
            if(tree[Root].child[1])
                return tree[tree[Root].child[1]].Min;
            return -1;
        }
};
int read()
{
    int rt = 0, in = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') in = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {rt = rt * 10 + ch - '0'; ch = getchar();}
    return rt * in;
}

class Splay_Tree_Type ST;

int n;
std :: map <int,int> Map;
std :: set <int> Set;


int main()
{
    int n = read();
    while(n--)
    {
        int op = read(), x = read();
        if(op == 1)
        {
            int num = ++Map[x];
            if(num == 1)
            {
                std :: set<int> :: iterator it1 = Set.insert(x).first, it2 = it1, it3;
                it2++;
                if(it1 != Set.begin())
                {
                    it3 = it1;
                    it3--;
                    ST.Insert(Key(x, x - *it3));
                }
                if(it2 != Set.end())    ST.Insert(Key(*it2, *it2 - x));
                if(it1 != Set.begin() && it2 != Set.end())
                {
                    it3 = it1;
                    it3--;
                    ST.Delete(Key(*it2, *it2 - *it3));
                }
            }
            else if(num == 2)   ST.Insert(Key(x, 0));
        }
        else if(op == 2)
        {
            int num = --Map[x];
            if(num == 1)    ST.Delete(Key(x, 0));
            else if(num == 0)
            {
                std::set<int>::iterator it1 = Set.lower_bound(x),it2 = it1, it3;
                it2++;
                if(it1 != Set.begin())
                {
                    it3 = it1;
                    it3--;
                    ST.Delete(Key(x, x - *it3));
                }
                if(it2 != Set.end())    ST.Delete(Key(*it2, *it2 - x));
                if(it1 != Set.begin() && it2 != Set.end())
                {
                    it3 = it1;
                    it3--;
                    ST.Insert(Key(*it2, *it2 - *it3));
                }
                Set.erase(Set.lower_bound(x));
            }
        }
        else
        {
            int num = Map[x];
            if(num > 1)
            {
                printf("Yes\n");
                continue;
            }
            std :: set <int> :: iterator it = Set.lower_bound(x);
            if(num == 1 && it != Set.begin())
            {
                printf("Yes\n");
                continue;
            }
            if(num == 0 && it != Set.begin())
            {
                it--;
                int num1 = *it, num2 = 0;
                if(it != Set.begin())
                {
                    it--;
                    num2 = *it;
                    if(num1 + num2 > x)
                    {
                        printf("Yes\n");
                        continue;
                    }
                }
            }
            ST.Insert(Key(x, -1));
            int p = ST.sol();
            ST.Delete(Key(x, -1));
            if(p == -1 || p >= x)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    system("pause");
    return 0;
}