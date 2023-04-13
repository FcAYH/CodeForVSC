#include <bits/stdc++.h>

using namespace std;
int value[18] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char M[18] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
void Solve()
{
    int n;
    scanf("%d", &n);
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int sum = 0;
        for (int j = 0; j < 18; j++)
        {
            sum += (s[j] - '0') * value[j];
        }
        int z = sum % 11;
        // cout << z << endl;
        if (s[17] != M[z])
            cout << s << endl;
        else
            count++;
    }
    if (count == n)
        cout << "All passed" << endl;
}

int main()
{
    Solve();

    return 0;
}
// 37090220010709243  8
