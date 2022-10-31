#include <bits/stdc++.h>

using namespace std;

int standard[60]; // A-65, z-122
int charCounter[60];
string emptyString = "";

bool Contains()
{
    for (int i = 0; i < 60; i++)
    {
        if (charCounter[i] < standard[i])
            return false;
    }

    return true;
}

string minWindow(string s, string t)
{
    memset(standard, 0, sizeof(standard));
    memset(charCounter, 0, sizeof(charCounter));
    int lenS = s.length(), lenT = t.length();

    for (int i = 0; i < lenT; i++)
    {
        standard[t[i] - 'A']++;
    }

    int right = 0, left = 0;
    int minLength = INT32_MAX, ansLeft = 0;
    while (right < lenS)
    {
        charCounter[s[right] - 'A']++;

        while (left <= right && Contains())
        {
            // printf("%d %d\n", left, right);
            if (right - left + 1 < minLength)
            {
                ansLeft = left;
                minLength = right - left + 1;
            }

            charCounter[s[left] - 'A']--;
            left++;
        }

        right++;
    }

    if (minLength == INT32_MAX)
        return emptyString;

    return s.substr(ansLeft, minLength);
}

void Solve()
{
    string s, t;
    cin >> s >> t;

    string result = minWindow(s, t);
    cout << result;
}

int main()
{
    Solve();

    return 0;
}

/*
ADOBECODEBANC
ABC

cabwefgewcwaefgcf
cae
*/
