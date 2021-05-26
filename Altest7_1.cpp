#include <iostream>
using namespace std;

template <class Type>
class Traveling
{
    friend Type Tsp(int **, int[], int, Type);

public:
    void Backtrack(int i);
    int n, *x, *bestx;
    Type **a, cc, bestc;
};
template <class Type>
Type Tsp(Type **a, int v[], int n);
int main()
{
    int **a, *v, n, bestc;
    cin >> n;
    v = new int[n + 1];
    a = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        a[i] = new int[n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    bestc = Tsp(a, v, n);
    cout << bestc;
    return 0;
}
template <class Type>
void Traveling<Type>::Backtrack(int i)
{
    int temp;
    if (i == n)
    {
        if (a[x[n - 1]][x[n]] != 0 && a[x[n]][x[1]] != 0 && (cc + a[x[n - 1]][x[n]] + a[x[n]][x[1]] < bestc || bestc == 0))
        {
            for (int j = 1; j <= n; j++)
            {
                bestx[j] = x[j];
                //printf("%d %d ", j, bestx[j]);
            }
            bestc = cc + a[x[n - 1]][x[n]] + a[x[n]][x[1]];
            printf("%d %d %d %d\n", bestc, cc, a[x[n - 1]][x[n]], a[x[n]][x[1]]);
        }
    }
    else
    {
        for (int j = i; j <= n; j++)
            if (a[x[i - 1]][x[j]] < bestc || bestc == 0)
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
                cc += a[x[i - 1]][x[i]];
                // printf("%d %d %d %d %d %d\n", i, j, x[j], temp, cc, a[x[i - 1]][x[i]]);
                // printf("i--%d j--%d x--%d temp--%d cc1--%d a--%d\n", i, j, x[j], temp, cc, a[x[i - 1]][x[i]]);
                Backtrack(i + 1);
                cc -= a[x[i - 1]][x[i]];
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
                // printf("%d %d %d %d %d %d\n", i, j, x[j], temp, cc, a[x[i - 1]][x[i]]);
                // printf("i--%d j--%d x--%d temp--%d cc2--%d a--%d\n", i, j, x[j], temp, cc, a[x[i - 1]][x[i]]);
                //printf("---------------------------------------------------------");
            }
    }
}
template <class Type>
Type Tsp(Type **a, int v[], int n)
{
    Traveling<Type> Y;
    Y.x = new int[n + 1];
    for (int i = 1; i <= n; i++)
        Y.x[i] = i;
    Y.a = a;
    Y.n = n;
    Y.bestc = 0;
    Y.bestx = v;
    Y.cc = 0;
    Y.Backtrack(2);
    delete[] Y.x;
    return Y.bestc;
}
/*
5
4 8 6 5 3 2 10 8 7 3
*/
