#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

uint GrayToDecimal(uint x)
{
    // ..
    return x;
}

uint BinaryToDecimal(uint x)
{
    uint factor = 1;
    uint ans = 0;

    while (x != 0)
    {
        ans += (x % 10) * factor;
        factor <<= 1;
        x /= 10;
    }
    return ans;
}

uint DecimalToBinary(uint x)
{
    uint ans = 0;
    int temp[5];
    int index = 0;

    while (x != 0)
    {
        temp[index++] = x % 2;
        x >>= 1;
    }

    while (--index >= 0)
    {
        ans = ans * 10 + temp[index];
    }

    return ans;
}

int main()
{
    map<string, string> Map;

    Map["0000"] = "0000";
    Map["0001"] = "0001";
    Map["0011"] = "0010";
    Map["0010"] = "0011";
    Map["0110"] = "0100";
    Map["0111"] = "0101";
    Map["0101"] = "0110";
    Map["0100"] = "0111";
    Map["1100"] = "1000";
    Map["1101"] = "1001";
    Map["1111"] = "1010";
    Map["1110"] = "1011";
    Map["1010"] = "1100";
    Map["1011"] = "1101";
    Map["1001"] = "1110";
    Map["1000"] = "1111";

    string x;
    cin >> x;
    cout << Map[x];

    // uint x;
    // scanf("%u", &x);
    // uint ans = DecimalToBinary(GrayToDecimal(BinaryToDecimal(x)));
    // printf("%u", ans);

    return 0;
}
