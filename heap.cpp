#include <bits/stdc++.h>

using namespace std;

//STL: 从大到小
void Solve()
{
    priority_queue<int> q;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        q.push(a);
        //从小到大则插入-a
    }

    for (int i = 0; i < n; i++)
        printf("%d ", q.top()), q.pop();
    //从小到大则输出-q.top()
}

int main()
{
    Solve();

    return 0;
}
