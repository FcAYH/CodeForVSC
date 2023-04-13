#include <bits/stdc++.h>

using namespace std;
int a[10001];
struct area
{
    int left, right;
};
vector<area> ans;
void Solve()
{
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    int flag = 0;
    int maxx = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        maxx = max(maxx, a[i]);
        if (a[i] > t)
        {
            // printf("[%d", i);
            if (flag == 0)
            {
                area a;
                a.left = i;
                ans.push_back(a);
            }
            flag = 1;
        }
        else
        {
            if (flag == 1)
            {
                ans[ans.size() - 1].right = i - 1;
            }
            flag = 0;
        }
    }
    if (flag)
        ans[ans.size() - 1].right = n - 1;
    if (ans.empty())
        cout << maxx;
    else
        for (int i = 0; i < ans.size(); i++)
            printf("[%d, %d]\n", ans[i].left, ans[i].right);
}

int main()
{
    Solve();

    return 0;
}
