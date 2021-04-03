#include <bits/stdc++.h>

using namespace std;

class Color
{
    friend int mColoring(int, int, int **);

public:
    bool Ok(int k);
    void Backtrack(int t);
    int n, m, **a, *x;
    long sum;
};
int mColoring(int n, int m, int **a);

int main()
{
    int n, m, **a, sum;
    cout << "Please input the number of colors:";
    cin >> m;
    cout << "Please input the number of nodes:";
    cin >> n;

    a = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        a[i] = new int[n + 1];
    cout << "Please input the relation of nodes: 1-->Connected,0-->Not connected:";

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cout << "Please input the relation of" << i << "and" << j << ":";
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    sum = mColoring(n, m, a);

    return 0;
}

bool Color::Ok(int k)
{
    for (int j = 1; j <= n; j++)
        if ((a[k][j] == 1) && (x[j] == x[k]))
            return false;
    return true;
}
void Color::Backtrack(int t)
{
    if (t > n)
    {
        sum++;
        for (int i = 1; i <= n; i++)
            cout << x[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            x[t] = i;
            if (Ok(t))
                Backtrack(t + 1);
            x[t] = 0;
        }
    }
}

int mColoring(int n, int m, int **a)
{
    Color X;
    X.n = n, X.m = m, X.a = a, X.sum = 0;

    int *p = new int[n + 1];
    for (int i = 0; i <= n; i++)
        p[i] = 0;

    X.x = p;
    X.Backtrack(1);

    delete[] p;
    return X.sum;
}
