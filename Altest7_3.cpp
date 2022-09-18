#include <bits/stdc++.h>

using namespace std;

class List
{
private:
    int *number;
    int length, allSum;
    vector<int> vec;

public:
    List(int x, int k) : length(x), allSum(k) { allSum = 0; }
    List(int x, int a[], int k) : length(x), allSum(k)
    {
        number = new int[length];
        for (int i = 0; i < length; i++)
            number[i] = a[i];

        allSum = 0;
    }
    ~List()
    {
        if (number != nullptr)
            delete[] number;
    }

private:
    void solve(int *a, int n, int sum);

public:
    void Calculate() { solve(number, length, allSum); }
};

void List::solve(int *a, int n, int sum)
{
    //a为输入数组，n为数组长度，sum为待查找的和，vec用于保存查找到的组合
    if (sum == 0)
    {
        vector<int>::iterator iter = vec.begin();
        for (; iter != vec.end(); iter++)
        {
            if (iter != vec.end() - 1)
                cout << *iter << "+";
            else
                cout << *iter;
        }
        cout << endl;
        return;
    }
    else if (sum < 0 || n <= 0)
        return;
    vec.push_back(a[0]); //a[0]即*a，注指针a是变化的，每次指向后一个
    solve(a + 1, n - 1, sum - a[0]);
    vec.pop_back();
    while (*a == *(a + 1) && a < a + n) //跳过重复的数字 
        a++;
    solve(a + 1, n - 1, sum);
}

int main()
{
    int k, n, a[100];
    cin >> k >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < a[i + 1])
        {
            int t = a[i];
            a[i] = a[i + 1];
            a[i + 1] = t;
        }
    }

    List *list = new List(n, a, k);
    list->Calculate();

    delete list;
}
//4 6 4 3 2 2 1 1
