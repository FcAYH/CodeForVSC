#include <bits/stdc++.h>

using namespace std;

class ServiceArrange
{
private:
    int s;
    vector<int> consumers;

public:
    ServiceArrange(vector<int> x, int s) : consumers(x), s(s) {}

public:
    double Arrangment();
};

double ServiceArrange::Arrangment()
{
    vector<int> st(s + 1, 0);
    vector<int> su(s + 1, 0);

    int n = consumers.size();

    sort(consumers.begin(), consumers.end());

    for (int i = 0; i < n; i++)
    {
        int temp = i % s;
        st[temp] += consumers[i];
        su[temp] += st[temp];
    }

    double temp = 0;
    for (int i = 0; i < s; i++)
        temp += su[i];
    temp /= n;

    return temp;
}

void Solve()
{
    int n, s;
    vector<int> x(0);

    scanf("%d%d", &n, &s);

    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        x.push_back(temp);
    }

    ServiceArrange service(x, s);

    printf("%.2lf\n", service.Arrangment());
}

int main()
{
    Solve();

    return 0;
}
