#include <bits/stdc++.h>

using namespace std;

const int MaxN = 202;

struct node
{
    int i;
    int j;
    int val;
    node(int x, int y, int v) : i(x), j(y), val(v){};
};

struct cmp
{
    bool operator()(const node &a, const node &b) const
    {
        return a.val > b.val;
    }
};

void getKthSum(const vector<int> &arr1, const vector<int> &arr2, int k, vector<int> &result)
{
    int sz1 = arr1.size();
    int sz2 = arr2.size();

    if (sz1 == 0 || sz2 == 0)
    {
        return;
    }

    vector<vector<bool>> visited(sz1, vector<bool>(sz2, false));
    priority_queue<node, vector<node>, cmp> pq;
    int sum = arr1[0] + arr2[0];
    pq.push(node(0, 0, sum));
    visited[0][0] = true;

    int count = 0;

    while (!pq.empty() && count < k)
    {
        node e = pq.top();
        pq.pop();
        result.push_back(e.val);

        count++;
        int ex1 = e.i + 1;
        int ey1 = e.j;
        int ex2 = e.i;
        int ey2 = e.j + 1;
        if (ex1 < sz1 && !visited[ex1][ey1])
        {
            pq.push(node(ex1, ey1, arr1[ex1] + arr2[ey1]));
            visited[ex1][ey1] = true;
        }
        if (ey2 < sz2 && !visited[ex2][ey2])
        {
            pq.push(node(ex2, ey2, arr1[ex2] + arr2[ey2]));
            visited[ex2][ey2] = true;
        }
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> result;
    vector<int> arr[MaxN];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }

        sort(arr[i].begin(), arr[i].end());
    }

    getKthSum(arr[0], arr[1], k, result);

    for (int i = 2; i < n; i++)
    {
        arr[i - 1] = result;
        result.clear();
        getKthSum(arr[i - 1], arr[i], k, result);
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
/*
3 3 3
2 1 3
1 1 2
3 4 2

1 2 3
1 1 2
2 3 4

4 4 5
*/
