#include <iostream>
#include <cmath>
using namespace std;
int max_product(int x)
{
    if (x == 1)
        return 1;
    if (x == 2)
        return 1;
    if (x == 3)
        return 2;
    if (x >= 4)
    {
        long long int result;
        int m = x % 3; // m为余数
        int n = x / 3; // n为商
        if (m == 0)
            result = pow(3, n);
        else if (m == 1)
            result = pow(3, n - 1) * 4;
        else
            result = pow(3, n) * 2;
        return result;
    }
}
int main()
{
    int y;
    cin >> y;
    cout << max_product(y) << endl;
    return 0;
}
