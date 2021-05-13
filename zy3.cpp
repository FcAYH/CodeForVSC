//二分的边界条件容易混 仔细考虑一下

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100100;
int n;
int len; //记录当前最多能拦截多少导弹
         //(实际是最长不升子序列即x数组的长度)
    //同时是最后的答案
int a[maxn]; //存所有的导弹
int x[maxn]; //存当前拦截的导弹的高度
int main()
{
    while (scanf("%d", &a[++n]) == 1)
        x[n] = 1;
    n--;

    //第一问
    for (int i = 1; i <= n; i++)
    {
        //可以拦截或x数组为空 直接加入x数组
        if (len == 0 || a[i] <= x[len])
            x[++len] = a[i];
        //不可以拦截 二分查找可以替换的位置
        else
        {
            int l = 1, r = len;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (a[i] > x[mid])
                    r = mid;
                else
                    l = mid + 1;
            }
            x[l] = a[i]; //替换
        }
    }
    printf("%d\n", len);

    //第二问(除了<=改成> 同第一问)
    for (int i = 1; i <= n; i++)
    {
        if (len == 0 || a[i] > x[len])
            x[++len] = a[i];
        else
        {
            int l = 1, r = len;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (a[i] <= x[mid])
                    r = mid;
                else
                    l = mid + 1;
            }
            x[l] = a[i];
        }
    }
    printf("%d\n", len);
    return 0;
}
