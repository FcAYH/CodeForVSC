#include <bits/stdc++.h>

using namespace std;

vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> result;
    int strLength = s.length();
    int wordCount = words.size();
    int wordLength = words[0].length();
    map<string, int> wordsMap;

    for (int i = 0; i < words.size(); i++)
        wordsMap[words[i]]++;

    if (wordCount * wordLength > strLength)
        return result;

    for (int start = 0; start < wordLength; start++)
    {
        map<string, int> checkMap;
        int i = start;
        int left = i;

        while (i <= strLength - wordLength)
        {
            // 新增一个str
            string newSub = s.substr(i, wordLength);
            checkMap[newSub]++;

            if (i - left >= wordCount * wordLength)
            {
                string lastSub = s.substr(left, wordLength);
                checkMap[lastSub]--;
                if (checkMap[lastSub] == 0)
                    checkMap.erase(lastSub);

                left += wordLength;
            }

            // cout << left << " " << i << " " << checkMap.size() << " " << wordsMap.size() << endl;
            if (checkMap == wordsMap)
                result.push_back(left);

            i += wordLength;
        }
    }

    return result;
}

void Solve()
{
    string s;
    int n;
    vector<string> words;

    cin >> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        words.push_back(word);
    }

    vector<int> result = findSubstring(s, words);
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
barfoofoobarthefoobarman
3
bar
foo
the

lingmindraboofooowingdingbarrwingmonkeypoundcake
5
fooo
barr
wing
ding
wing
*/
