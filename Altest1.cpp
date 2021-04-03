#include <bits/stdc++.h>

using namespace std;

//Convert decimal to binary
class DToB
{
public:
    DToB() {}
    DToB(int val)
    {
        this->val = val;
    }
    const void DecimalToBinary();
    void getval();

private:
    int val;
};

const void DToB::DecimalToBinary()
{
    int Bin[20], Nowp = 0;
    int calc_v = this->val;

    while (calc_v)
    {
        Bin[++Nowp] = calc_v % 2;
        calc_v /= 2;
    }

    for (int i = Nowp; i >= 1; i--)
        printf("%d", Bin[i]);
}
void DToB::getval()
{
    scanf("%d", &this->val);
}

void Solve()
{
    DToB work;

    work.getval();
    work.DecimalToBinary();
}

int main()
{
    Solve();

    return 0;
}
