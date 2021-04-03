#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int n,m,k;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1; i <= k; i++)
    {
        int nowb = 1,cb,flag = 0;
        stack<int> s;
        for(int j = 1; j <= n; j++)
        {
            scanf("%d",&cb);
            if(flag) continue ;
            if(cb == nowb){nowb++; continue ;}
            else 
            {
                while(s.size() && s.top() == nowb) nowb++,s.pop();
                if(s.size() < m) s.push(cb);
                else flag = 1;
            }
        }
        while(s.size() && s.top() == nowb) nowb++,s.pop();
        if(s.size()) flag = 1;
        if(i != k) flag ? printf("NO\n") : printf("YES\n");
        else flag ? printf("NO") : printf("YES");
    }
    system("pause");
    return 0;
}
/*
7 5 4
7 6 1 3 2 5 4
3 1 5 4 2 6 7
7 6 5 4 3 2 1


7 6 5 4 3 1 2
*/