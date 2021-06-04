
//把自然数N分解成若干个互不相同的正整数，使乘积最大；
/**
题意挺晦涩的，就是说要维持这个会议召开需要满足几个条件，而要会议召开最久需要这个条件尽可能久的维持
接着就需要了将整数N分解任意个不同的整数，使这些整数的乘积最大
将N分解为N=a1+a2+a3+..+ak
可以归纳出这么一些规律
1.a1>1  如果a1=1，那么将a1加到ak上，必然使得到的这个乘积大于原来的乘积
2.2>=rec[i+1]-rec[i]>=1,因为如果出现>2,可以将rec[i+1],rec[i]改为rec[i+1]-1,rec[i]+1，使得到的乘积更大
3.最多只有一个i,使得rec[i+1]-rec[i]=2
  反证法，假设i<j,并且rec[i+1]-rec[i]=2,rec[j+1]-rec[j]=2,那么将rec[i],rec[j+1]替换成rec[i]+1,rec[j+1]-1
  将使得乘积更大
4.a1<=3 如果a1>=4,那么将a1,a2替换成2,a1-1,a2-1将使得乘积更大
5.如果a1=3,并且存在一个i使得rec[i+1]-rec[i]=2，那么i一定为t-1
做法就是求出以2起始的最大连续自然数序列之和sum，使得sum的值不超过输入数n，
然后分情况讨论：
设此最大序列为2、3、……、w，则：
1。若剩余值（n-sum）等于w，则最后输出序列为：3、4、……、w、w+2，即将原最大序列每项加1，再将最后剩余的一个1加到最后一项上。
2。若剩余值（n-sum）小于w，则从序列的最大项i开始，从大到小依次将每项加1，直到剩余值用完。
*/
#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1001;

class Divide
{
private:
    int *rec;
    int n;

public:
    Divide(int x) : n(x)
    {
        rec = new int[n];
    }
    ~Divide()
    {
        if (rec != nullptr)
            delete[] rec;
    }

public:
    int *DivideN();
};

int *Divide::DivideN()
{
    int sum = 0, l = 1, left = 0;

    for (int i = 2; i <= n; i++)
    {
        rec[l++] = i;
        sum += i;

        if (sum > n)
        {
            sum -= i, l--, left = n - sum;
            break;
        }
    }

    for (int i = l - 1; left; left--)
    {
        rec[i]++;
        i--;
        if (i < 0)
            i = l - 1;
    }

    rec[0] = l - 1;

    return rec;
}

void Solve()
{
    int n;
    scanf("%d", &n);

    Divide divide(n);

    int *Ans = divide.DivideN();

    int ansVal = 1;
    for (int i = 1; i <= Ans[0]; i++)
    {
        ansVal *= Ans[i];
        printf("%d ", Ans[i]);
    }

    printf("\n%d\n", ansVal);
    //printf("%d\n", divide.DivideN());
}

int main()
{
    Solve();

    return 0;
}
