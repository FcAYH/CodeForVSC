#include <bits/stdc++.h>

using namespace std;

vector<int> FindWords(string s, vector<string> words)
{
    vector<int> result;

    map<string, int> wordMap;
    int wordLength = words[0].length();

    for (int i = 0; i < words.size(); i++)
    {
        wordMap[words[i]]++;
    }

    for (int i = 0; i < s.length(); i++)
    {
        string substring = s.substr(i, wordLength);

        if (wordMap.find(substring) != wordMap.end())
        {
            int cnt = 1;
            map<string, int> copiedMap = wordMap;
            copiedMap[substring]--;
            if (copiedMap[substring] == 0)
                copiedMap.erase(substring);

            for (int j = i + wordLength; j < s.length(); j += wordLength)
            {
                string sub = s.substr(j, wordLength);
                if (copiedMap.find(sub) != copiedMap.end())
                {
                    cnt++;
                    copiedMap[sub]--;
                    if (copiedMap[sub] == 0)
                        copiedMap.erase(sub);
                }
                else
                    break;
            }

            if (cnt == words.size())
            {
                result.push_back(i);
            }
        }
    }

    return result;
}

void Solve()
{
    string s;
    cin >> s;

    int n;
    cin >> n;
    vector<string> words;

    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        words.push_back(word);
    }

    vector<int> result = FindWords(s, words);

    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
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
foo
bar
the

wordgoodgoodgoodbestword
4
word
good
best
word
*/
