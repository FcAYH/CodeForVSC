#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Mod = 40020831;

class Solution
{
public:
    ll countTriplets(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, ll> cnt, total;
        ll ans = 0ll;
        int s = 0;
        for (int k = 0; k < n; ++k)
        {
            int val = arr[k];
            if (cnt.count(s ^ val))
            {
                ans += cnt[s ^ val] * (ll)k - total[s ^ val];
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
    printf("%lld", solve.countTriplets(arr));
}

int main()
{
    Solve();

    return 0;
}
