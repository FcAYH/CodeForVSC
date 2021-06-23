#include <bits/stdc++.h>

using namespace std;

const int Inf = 0x3f3f3f3f;
const int Maxn = 1001;

int n, cnt = 0, not_bip = 0; //cnt记录操作数，目测cnt最后会等于2*n因为每个数都要进栈和出栈
int len1 = 0, len2 = 0;      //记录两个栈的大小
int Wait_print = 1;          //我们当前该输出啥数
int dt[Maxn][Maxn];          //存图
int Sm[Maxn];                //后缀最小值
int sl[Maxn];                //原数列
int col[Maxn];               //每个数的颜色
int vis[Maxn];               //Bfs visit数组
int stack1[Maxn];            //1栈
int stack2[Maxn];            //2栈
char Oper[2020];             //操作，这个数组可以不开，大家可以在过程中直接输出，而且会更快

void Suffix_min() //预处理后缀最小值
{
    Sm[n] = sl[n];
    for (int i = n - 1; i >= 1; i--)
    {
        Sm[i] = min(Sm[i + 1], sl[i]);
    }
}

void build_edge() //建边
{
    //memset(dt, 0x3f, sizeof(dt));

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (Sm[j] < sl[i] && sl[i] < sl[j])
            {
                //满足这种条件下，单栈GG了，那么把i，j放到不同的栈里
                dt[i][j] = 1; //先在ij之间添一条边 ，
                dt[j][i] = 1; //等会染色就可以把他们标记上不同的颜色
            }
        }
    }
}

void Bipartitegraph_dyeing(int poi) //这个函数名翻译成中文叫：二分图染色
{
    //我用Bfs的方法用0/1进行染色。
    queue<int> Q;
    Q.push(poi);

    col[poi] = 0;
    vis[poi] = 1;

    while (!Q.empty())
    {
        int st = Q.front();
        Q.pop();

        for (int i = 1; i <= n; i++)
        {
            if (dt[st][i] != 0 && col[i] == col[st])
            { //这个条件满足，就说明该图不是二分图，
                not_bip = 1;
                return;
            } //也就是说存在了a4<a1<a2<a3这种操作 。
            if (dt[st][i] != 0 && col[i] == -1 && !vis[i])
            {
                col[i] = 1 - col[st];
                vis[i] = 1;
                Q.push(i);
            }
        }
    }
} //这样，我们就把所有数分成了col=1和col=0两类，0压1栈，1压2栈

void Simulate() //我们来模拟一下排序过程（保证字典序最小）
{
    sl[0] = Inf;       //避免在len--时减到负数
    Oper[++cnt] = 'a'; //先把第一个数压进 1栈
    stack1[++len1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (col[i] == 0)
        {
            //我们要维护两个栈内的数都是单调不升的
            while (sl[i] > sl[stack1[len1]])
            {
                Oper[++cnt] = 'b';
                len1--;
                Wait_print++;
                //根据我们上面的过程，这里弹出去的一定符合顺序
                //不会把较大的数先弹出去
            }
            Oper[++cnt] = 'a';
            stack1[++len1] = i;
        }

        if (col[i] == 1)
        {
            //这里要注意了，因为我们要字典序最小
            //所以在往2栈填数时，先考虑一下1栈可不可以弹数
            while (sl[stack1[len1]] == Wait_print)
            {
                Oper[++cnt] = 'b';
                len1--;
                Wait_print++;
            }
            while (sl[i] > sl[stack2[len2]])
            {
                Oper[++cnt] = 'd';
                len2--;
            }

            Oper[++cnt] = 'c';
            stack2[++len2] = i;
        }
    }

    while (len1 > 0 && len2 > 0)
    {
        if (sl[stack1[len1]] <= sl[stack2[len2]])
        {
            Oper[++cnt] = 'b';
            len1--;
        }
        else
        {
            Oper[++cnt] = 'd';
            len2--;
        }
    }

    for (int i = len1; i >= 1; i--)
        Oper[++cnt] = 'b';

    for (int i = len2; i >= 1; i--)
        Oper[++cnt] = 'd';
}

int main()
{
    scanf("%d", &n); //读入n

    //读入数列
    for (int i = 1; i <= n; i++)
        scanf("%d", &sl[i]);

    Suffix_min();
    build_edge();

    memset(col, -1, sizeof(col));

    for (int i = 1; i <= n; i++)
        if (col[i] == -1)
            Bipartitegraph_dyeing(i);

    if (not_bip)
    {
        printf("0\n");
        return 0;
    }

    Simulate();

    for (int i = 1; i <= cnt - 1; i++)
        printf("%c ", Oper[i]);

    printf("%c", Oper[cnt]);

    return 0;
}
