#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100010;
const char vowelLetters[] = {'a', 'e', 'i', 'o', 'u'};

char input[MaxN];

bool IsVowelLetter(char x)
{
    for (int i = 0; i < 5; i++)
        if (x == vowelLetters[i])
            return true;

    return false;
}

void Solve()
{
    scanf("%s", input);
    int k;
    scanf("%d", &k);

    int length = strlen(input);
    int ans = 0, cnt = 0;
    for (int i = 0; i < k; i++)
    {
        if (IsVowelLetter(input[i]))
            cnt++;
    }

    ans = cnt;
    for (int i = k; i < length; i++)
    {
        if (IsVowelLetter(input[i]))
            cnt++;
        if (IsVowelLetter(input[i - k]))
            cnt--;

        ans = max(ans, cnt);
    }

    printf("%d", ans);
}

int main()
{
    Solve();

    return 0;
}
