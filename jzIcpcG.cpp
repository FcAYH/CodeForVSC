#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;

char s1[MAXN * 2];
char s2[MAXN * 2];
char s3[MAXN * 2];
// char ans[MAXN * 3];

void Solve()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);
        scanf("%s%s%s", s1, s2, s3);

        int ptr1 = 0, ptr2 = 0, ptr3 = 0, ptrAns = 0;
        string ans;

        while (ptr1 < 2 * n && ptr2 < 2 * n && ptr3 < 2 * n)
        {
            // if (s1[ptr1] == s2[ptr2] && s1[ptr1] == s3[ptr3])
            // {
            //     ans[ptrAns] = s1[ptr1];
            //     ptr1++;
            //     ptr2++;
            //     ptr3++;
            // }
            if (s1[ptr1] == s2[ptr2])
            {
                ans += s1[ptr1];
                ptr1++;
                ptr2++;
            }
            else if (s1[ptr1] == s3[ptr3])
            {
                ans += s1[ptr1];
                ptr1++;
                ptr3++;
            }
            else if (s2[ptr2] == s3[ptr3])
            {
                ans += s2[ptr2];
                ptr2++;
                ptr3++;
            }
            ptrAns++;
        }
        if (ptr1 >= 2 * n)
        {
            if (ptr2 >= ptr3)
            {
                for (int i = ptr2; i < 2 * n; i++)
                    ans += s2[i];
            }
            else
            {
                for (int i = ptr3; i < 2 * n; i++)
                    ans += s3[i];
            }
        }
        else if (ptr2 >= 2 * n)
        {
            if (ptr1 >= ptr3)
            {
                for (int i = ptr1; i < 2 * n; i++)
                    ans += s1[i];
            }
            else
            {
                for (int i = ptr3; i < 2 * n; i++)
                    ans += s3[i];
            }
        }
        else if (ptr3 >= 2 * n)
        {
            if (ptr1 >= ptr2)
            {
                for (int i = ptr1; i < 2 * n; i++)
                    ans += s1[i];
            }
            else
            {
                for (int i = ptr2; i < 2 * n; i++)
                    ans += s2[i];
            }
        }

        // ans[ptrAns] = '/0';
        // while (ptrAns < 3 * n)
        // {
        //     ans[ptrAns] = '0';
        //     ptrAns++;
        // }
        while (ans.length() != 3 * n)
            ans += '0';

        cout << ans << endl;
    }
}

int main()
{
    Solve();

    return 0;
}

/*
2
1
11
10
00
4
01100100
11101010
01000111


1
4
00000000
00011111
11100111

2
4
00000001
00000010
00000100
4
00000001
00000100
11111111
*/
