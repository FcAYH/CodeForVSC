
//input.txt
//10 2
//56 12 1 99 1000 234 33 55 99 812
//output.txt
//336
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
        int temp = i % s;         //第i的任务由第i%s处处理
        st[temp] += consumers[i]; //在第j处处理的任务运行时间之和
        su[temp] += st[temp];     //在第j处处理的任务等待时间之和
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
