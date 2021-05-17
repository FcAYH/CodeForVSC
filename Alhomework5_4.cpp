#include <bits/stdc++.h>

using namespace std;

class Sequence
{
private:
    int length;
    int *data;

public:
    Sequence() {}
    Sequence(int length) : length(length) {}
    ~Sequence()
    {
        if (data != nullptr)
            delete[] data;
    }

public:
    void SetLength(int length) { this->length = length; }
    void SetData();
    int LongestIncreasingSequence();
};

void Sequence::SetData()
{
    this->data = new int[this->length + 1];

    for (int i = 1; i <= length; i++)
        scanf("%d", &data[i]);
}
int Sequence::LongestIncreasingSequence()
{
    int *temp = new int[this->length + 1];
    int Ans = 0;

    memset(temp, 0, sizeof(int) * (length + 1));

    for (int i = 2; i <= length; i++)
    {
        for (int j = 1; j <= i; j++)
            if (data[i] > data[j])
                temp[i] = max(temp[i], temp[j] + 1);
        Ans = max(Ans, temp[i]);
    }

    return Ans;
}

void Solve()
{
    int *n = new int;
    scanf("%d ", n);
    Sequence *sequence = new Sequence(*n);
    sequence->SetData();

    printf("%d\n", sequence->LongestIncreasingSequence());

    delete n, sequence;
}

int main()
{
    Solve();

    return 0;
}
