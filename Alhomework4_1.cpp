#include <bits/stdc++.h>

using namespace std;

const int Maxn = 33;
const int Maxd = 100;

class DivideNumber
{
private:
    int n, cnt, sum;
    int tmp[Maxn];
    int Ans[Maxd][Maxn];

public:
    DivideNumber() : cnt(0), sum(0) {}
    DivideNumber(int x) : n(x), cnt(0), sum(0) {}
    ~DivideNumber() {}

private:
    void dividing(int x);

public:
    void Setn(int x) { this->n = x; }
    void Divide();
    void Print();
};

void DivideNumber::dividing(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (!(x % i))
        {
            tmp[++cnt] = i;
            dividing(x / i);
            if (x / i != i)
            {
                tmp[cnt] = x / i;
                dividing(i);
            }
            cnt--;
        }
    }

    sum++;
    for (int i = 1; i <= cnt; i++)
        Ans[sum][++Ans[sum][0]] = tmp[i];
    Ans[sum][++Ans[sum][0]] = x;
}

void DivideNumber::Divide()
{
    this->dividing(n);
}
void DivideNumber::Print()
{
    printf("%d\n", sum);
    for (int i = 1; i <= sum; i++)
    {
        printf("%d = ", n);
        for (int j = 1; j < Ans[i][0]; j++)
            printf("%d * ", Ans[i][j]);
        printf("%d\n", Ans[i][Ans[i][0]]);
    }
}

void Solve()
{
    int n;
    scanf("%d", &n);

    DivideNumber *N = new DivideNumber(n);

    N->Divide();
    N->Print();

    delete N;
}

int main()
{
    Solve();

    return 0;
}
