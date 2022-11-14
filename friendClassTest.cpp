#include <bits/stdc++.h>

using namespace std;

class PrivA
{
public:
    int id;
    friend class FriendB;

private:
    PrivA() {}
};

class FriendB
{
public:
    PrivA *MakeObjectPrivA()
    {
        PrivA *A = new PrivA();
        A->id = 1;
        return A;
    }
};

int main()
{
    FriendB B;
    PrivA *a = B.MakeObjectPrivA();

    printf("%d\n", a->id);
}
