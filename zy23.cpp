#include <iostream>
#include <climits>
#define N 100
using namespace std;
int buf[N][N];
int sum[N][N]; //辅助矩阵，其中sum[i][j]存储的是前i行的第j列的累加之和
int b[N];
int max(int a, int b) { return a > b ? a : b; }
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> buf[i][j];
        }
    }
    for (int i = 0; i < n; i++) //初始化第一行
        sum[0][i] = buf[0][i];
    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            sum[i][k] = sum[i - 1][k] + buf[i][k]; //累加上一行的值求和
        }
    }
    int Ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int cursum = 0;
            for (int k = 0; k < n; k++)
            {
                if (i == 0)
                {
                    b[k] = sum[j][k];
                }
                else
                {
                    b[k] = sum[j][k] - sum[i - 1][k];
                    //得到第i行到第j行的累加之和
                }
                cursum = max(b[k], b[k] + cursum);
                Ans = max(Ans, cursum);
            }
        }
    }
    cout << "The max sum of subarray is: " << Ans << endl;
    return 0;
}
