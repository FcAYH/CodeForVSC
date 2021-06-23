#include <bits/stdc++.h>

using namespace std;

class Set
{
private:
    int *array;
    int n;

public:
    Set(int n, int *numbers) : n(n)
    {
        array = new int[n];
        for (int i = 0; i < n; i++)
            array[i] = numbers[i];
    }
    Set(const Set &t)
    {
        this->n = t.n;
        array = new int[this->n];
        for (int i = 0; i < n; i++)
            array[i] = t.array[i];
    }
    ~Set()
    {
        if (this->array != nullptr)
            delete[] array;
    }

private:
    int toSum;
    int flag = 0;
    vector<int> Ans;
    vector<int> temp;

    void dfs(int cur, int sum);

public:
    void SetN(int x) { this->n = x; }
    void SetNumbers(int x, int *numbers)
    {
        this->array = new int[x];
        for (int i = 0; i < x; i++)
            this->array[i] = numbers[i];
    }

    vector<int> FindSubSet(int x)
    {
        toSum = x;

        dfs(0, 0);

        return Ans;
    }
};

void Set::dfs(int cur, int sum)
{
    if (flag)
        return;

    if (sum == toSum)
    {
        Ans = temp;
        flag = 1;
        return;
    }

    if (sum > toSum || cur >= n)
        return;

    temp.push_back(array[cur]);
    dfs(cur + 1, sum + array[cur]);
    temp.pop_back();

    dfs(cur + 1, sum);
}

void Solve()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int *numbers = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    Set set(n, numbers);

    vector<int> printAns = set.FindSubSet(q);

    if (printAns.size() == 0)
        printf("No Solution!\n");
    else
    {
        for (int i = 0; i < printAns.size(); i++)
            printf("%d ", printAns[i]);
        puts("");
    }
}

int main()
{
    Solve();

    return 0;
}

/*
5 3
2 2 6 5 4


5 -1
3 9 1 8 2


5 10
3 9 1 8 2


*/
