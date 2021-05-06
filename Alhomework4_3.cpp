#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1024;

class Gray
{
private:
    int n, k;
    int **code;

public:
    Gray() {}
    Gray(int x) : n(x)
    {
        k = pow(2, n);
        code = new int *[k + 1];
        for (int i = 0; i <= k; i++)
            code[i] = new int[n + 1];
    }
    ~Gray() { delete[] code; }

private:
    void Graying(int x, int l, int r);

public:
    void MakeGrayCode();
    void Print();
};

void Gray::Graying(int x, int l, int r)
{
    if (x == 0)
        return;

    for (int i = l; i <= r; i++)
        code[i][x] = 0;

    int len = r - l + 1;
    Graying(x - 1, l, l + len / 2 - 1);

    for (int i = l + len / 2; i <= r; i++)
        for (int j = x - 1; j >= 1; j--)
            code[i][j] = code[r - i + 1][j];
    for (int i = l + len / 2; i <= r; i++)
        code[i][x] = code[r - i + 1][x] ^ 1;
}
void Gray::MakeGrayCode()
{
    for (int i = 1; i <= k / 2; i++)
        code[i][n] = 0;

    Graying(n - 1, 1, k / 2);

    for (int i = k / 2 + 1; i <= k; i++)
        for (int j = n - 1; j >= 1; j--)
            code[i][j] = code[k - i + 1][j];
    for (int i = k / 2 + 1; i <= k; i++)
        code[i][n] = code[k - i + 1][n] ^ 1;
}
void Gray::Print()
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = n; j >= 1; j--)
            printf("%d", code[i][j]);
        puts("");
    }
}

void Solve()
{
    int n;
    scanf("%d", &n);

    Gray *G = new Gray(n);

    G->MakeGrayCode();
    G->Print();

    delete G;
}

int main()
{
    Solve();

    return 0;
}
/*

000
001
011
010
110
111
101
100
根据观察，找到规律，对于n位格雷码，一共有2^n个数，首先对于第n位，前2^(k-1)个为0，后2^(k-1)个为1
然后对于第n-1位的前2^(k-1)个数，其中前2^(k-2)个为0，剩下为1，继续递归可以得到如下：
n=3时
000
00
0
0
n=4时
0 0 0 0
0 0 0
0 0
0 0
0 
0
0
0
随后当我们在回溯过程中，当处在处理第i位的函数中时，将从1到i-1位的全部赋值为上半部分的镜像
并将第i位赋值为上半部分取反
n=4时回溯到第3位时：
0 0 0 0
0 0 0 1
0 0 1 1
0 0 1 0
0 * . .
0 * . .
0 * . .
0 * . .
为 * 的位置为上半部分取反，为 . 的位置为上半部分镜像

首先输出为2^n个数，故输出复杂度为2^n

递归时仅递归了n层，但是每层包含一个二层for循环，两个一层for循环
两个一层for循环由上到下均为2^i，(i表示当前层的位数)
二层for循环的复杂度为(2^i)*i
故总复杂度为：
*/
