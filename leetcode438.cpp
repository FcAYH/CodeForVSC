#include <bits/stdc++.h>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> result;

    int lenS = s.length(), lenP = p.length();

    int standard[26];
    memset(standard, 0, sizeof(standard));

    for (int i = 0; i < lenP; i++)
        standard[p[i] - 'a']++;

    int charCounter[26];
    memset(charCounter, 0, sizeof(charCounter));

    int left = 0;
    for (int i = 0; i < lenS; i++)
    {
        charCounter[s[i] - 'a']++;
        if (i - left >= lenP)
        {
            charCounter[s[left] - 'a']--;
            left++;
        }

        // check
        bool isOk = true;
        for (int i = 0; i < 26; i++)
        {
            if (charCounter[i] != standard[i])
            {
                isOk = false;
                break;
            }
        }

        if (isOk)
            result.push_back(left);
    }

    return result;
}

void Solve()
{
    string s, p;
    cin >> s >> p;

    vector<int> result = findAnagrams(s, p);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    Solve();

    return 0;
}
/*
cbaebabacd
abc
*/
