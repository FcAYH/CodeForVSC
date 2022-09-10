#include <iostream>
#define ll long long
#define T 1000100
using namespace std;

const ll Mod = 1e9 + 7;

ll Euler[T + 1]; //因为我是从1开始索引所以开了T+1的数组
int main()
{
    //让第一项为0
    Euler[1] = 0;
    //第一步
    for (int i = 2; i <= T; i++)
    {
        Euler[i] = i;
    }
    //第二步
    for (int i = 2; i <= T; i++)
    {
        if (Euler[i] == i)
        {
            for (int j = i; j <= T; j += i)
            {
                // 这里不可以直接写成 ( 1 - 1/i );因为1/i(滑稽)
                // 通分一下（ 1 - 1/i ）= ( i - 1 )/i
                Euler[j] = Euler[j] / i * (i - 1); //然后要先除后乘
            }
        }
    }
    //第三步
    for (int i = 2; i <= T; i++)
    {
        Euler[i] += Euler[i - 1];
    }
    //输入输出
    int n;
    cin >> n;
    cout << Euler[n] << endl;
    return 0;
}
