#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    string a, b;
    int pa, pb;
    cin >> a >> pa >> b >> pb;
    int suma = 0, sumb = 0;
    int cnta = 0, cntb = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] - '0' == pa)
        {
            suma += pa * pow(10, cnta);
            cnta++;
        }
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] - '0' == pb)
        {
            sumb += pb * pow(10, cntb);
            cntb++;
        }
    }
    cout << suma + sumb;
}

int main()
{
    Solve();

    return 0;
}
