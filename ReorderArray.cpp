#include <bits/stdc++.h>

using namespace std;

void rearrangeArray(int arr[], int N)
{
    map<int, int> mp;

    for (int i = 0; i < N; i++)
    {
        mp[arr[i]]++;
    }

    priority_queue<pair<int, int>> pq;

    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }

    vector<int> result(N);

    pair<int, int> prev = {-1, -1};
    int current = 0;

    while (pq.size() != 0)
    {
        pair<int, int> k = pq.top();
        pq.pop();
        result[current] = k.second;

        if (prev.first > 0)
        {
            pq.push(prev);
        }

        k.first--;
        prev = k;
        current++;
    }

    for (auto it : result)
    {
        if (it == 0)
        {
            cout << "-1" << endl;
            return;
        }
    }

    for (auto it : result)
    {
        cout << it << ", ";
    }
}

// Driver Code
int main()
{
    int n;
    scanf("%d", &n);

    int *A = new int[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    rearrangeArray(A, n);
    delete A;
}
