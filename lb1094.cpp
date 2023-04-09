#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int stringToNum(string s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += (s[i] - '0') * pow(10, s.length() - i - 1);
    }
    //  cout << sum;
    return sum;
}
bool isPrime(string s)
{
    int n = stringToNum(s);
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, a;
    scanf("%d%d", &n, &a);
    string s;
    cin >> s;
    for (int i = 0; i <= n - a; i++)
    {
        if (isPrime(s.substr(i, a)))
        {
            cout << s.substr(i, a);
            return 0;
        }
    }
    cout << "404" << endl;
    return 0;
}
