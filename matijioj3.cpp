#include <bits/stdc++.h>

using namespace std;

string names[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

void Solve()
{
    int n;
    cin >> n;
    // scanf("%d", &n);

    long long powValue = 2;
    int range = 0;
    while ((powValue - 1) * 5 < n)
    {
        powValue <<= 1;
        range++;
    }
    // printf("%d", range);

    int sum = ((powValue >> 1) - 1) * 5;
    if (range != 0)
        n -= sum;

    // cout << n << " " << sum << " " << (n - 1) / range << endl;
    cout << names[(int)((n - 1) / pow(2, range))];
}

int main()
{
    Solve();

    return 0;
}
