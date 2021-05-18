#include <bits/stdc++.h>

using namespace std;

const int Mod = 40020831;

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> cnt, total;
        int ans = 0, s = 0;
        for (int k = 0; k < n; ++k)
        {
            int val = arr[k];
            if (cnt.count(s ^ val))
            {
                ans += cnt[s ^ val] * k - total[s ^ val];
                ans %= Mod;
            }
            ++cnt[s];
            total[s] += k;
            total[s] %= Mod, cnt[s] %= Mod;
            s ^= val;
        }
        return ans;
    }
};

void Solve()
{
    freopen("10.in", "r", stdin);
    freopen("10.out", "w", stdout);

    int n;
    scanf("%d", &n);

    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        arr.push_back(x);
    }

    Solution solve;
    printf("%d", solve.countTriplets(arr));
}

int main()
{
    Solve();

    return 0;
}
