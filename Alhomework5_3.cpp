#include <bits/stdc++.h>

using namespace std;

class Triangle
{
private:
    int count;
    int row;
    int **data;

public:
    Triangle() {}
    Triangle(int count) : count(count) {}
    ~Triangle()
    {
        if (data != nullptr)
            delete[] data;
    }

public:
    void SetRow(int x) { this->row = x; }
    void SetArray();
    int LongestPath();
};

void Triangle::SetArray()
{
    int blurSize = sqrt(count) * 2;
    data = new int *[blurSize + 1];
    for (int i = 0; i <= blurSize; i++)
        data[i] = new int[blurSize + 1];

    for (int i = 0; i <= blurSize; i++)
        for (int j = 0; j <= blurSize; j++)
            data[i][j] = 0;

    int cnt = 0;
    for (int i = 1; i; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cnt++;
            scanf("%d", &data[i][j]);
        }
        if (cnt == count)
        {
            this->row = i;
            break;
        }
    }
}
int Triangle::LongestPath()
{
    int Ans = 0;
    for (int i = 1; i <= this->row; i++)
        for (int j = 1; j <= i; j++)
            data[i][j] += max(data[i - 1][j - 1], data[i - 1][j]), Ans = max(Ans, data[i][j]);

    return Ans;
}

void Solve()
{
    int *n = new int;
    scanf("%d", n);

    Triangle *triangle = new Triangle(*n);
    triangle->SetArray();

    printf("%d\n", triangle->LongestPath());

    delete n, triangle;
}

int main()
{
    Solve();

    return 0;
}
