#include <bits/stdc++.h>

using namespace std;

const int Maxn = 10;

int cnt = 0;
int qlist[Maxn];          //存放木块的长度
int loss, n, len, mn = 0; //存放木块每次切割的损失，存放木块的数量，长度，最少需要木块的数量
void Perm(int, int *, int, int, int, int, int set[Maxn][Maxn], int nlist[Maxn]);

int main()
{

    int *list;
    int set[Maxn][Maxn];
    int nlist[Maxn];
    memset(qlist, 0, sizeof(qlist));

    cin >> len >> loss;

    n = 0;
    //每组数据输入之后用-1作为结束，本程序只处理一组数据，如要处理多组，可做适当修改
    while (cin >> qlist[n] && qlist[n] != -1)
        n++;
    mn = n;
    list = new int[n];

    for (int i = 0; i < n; i++)
    {
        list[i] = i;
    }

    memset(set, 0, sizeof(set));
    memset(nlist, 0, sizeof(nlist));
    Perm(1, list, 0, 0, n - 1, 1, set, nlist);

    printf("ans: %d\n", mn);

    return 0;
}
/*************************************************************************************
 Perm函数参数定义：
 list--->原始序列，存放每一块木块的编号
 level-->搜索到第几层
 k------>list中搜索的起始位置
 m------>list中搜索的最后位置
 count-->第几块木料，木料的数量 
 set---->二维矩阵，存放每一块木料放的是第几个木块，
         set[i][j]=1表示第i块木料可以聚成第j块木块
 nlist-->当前树中存放的list中的第几个木块，存放了所有可以组成当前木料的木块
 *************************************************************************************/
void Perm(int node, int *list, int level, int k, int m, int count, int set[Maxn][Maxn], int nlist[Maxn])
{
    cnt++;
    printf(" %d\n", node);

    int i;
    int nset[Maxn][Maxn];
    int mlist[Maxn];
    int klist[Maxn];

    if (m == 0)
    {
        for (int l = k; l <= m; l++)
            set[count - 1][list[l]] = 1;
        //判断每一行中木块长度总和+每次废掉的木块是否超过一块木料的长度
        int flag = 0;
        for (int l = 0; l < count; l++)
        {
            int sum = 0;
            for (int h = 0; h < n; h++)
            {
                if (set[l][h] == 1)
                    sum += qlist[h] + loss;
            }

            if (sum > len + loss)
            {
                flag = 1;
                break;
            }
        }
        //如果所有都满足，则当前木料的块数是一种选择
        if (flag == 0)
            mn = mn > count ? count : mn;
        return;
    }
    //如果已经取完所有的木块，则返回上一层选取其他选的方法
    if (k > m)
        return;
    else
    {
        //对于每一块木料都有k-m种选取方法，并深度遍历，每次取下一个木块确保不重复取
        for (i = k; i <= m; i++)
        {
            //获取上一次在该树上选取的木块
            for (int l = 0; l < level; l++)
                klist[l] = nlist[l];
            //继续取下一层的木块
            klist[level] = list[i];
            //获取还剩余的木块
            int left = 0;
            for (int l = 0; l <= m; l++)
            {
                int s;
                for (s = 0; s <= level; s++)
                    if (list[l] == klist[s])
                        break;
                if (s > level)
                    mlist[left++] = list[l];
            }
            //设置当前木料所选取的所有木块，nset[l][h]=1表示第l块木料可能锯成第h块木块
            for (int l = 0; l < Maxn; l++)
                for (int h = 0; h < Maxn; h++)
                    nset[l][h] = set[l][h];

            for (int l = 0; l <= level; l++)
                nset[count - 1][klist[l]] = 1;
            //如果所有木块均已取完，则是一种选择，求出满足条件的木料的数量，并计算最小的木料数
            left--;
            if (left < 0)
            {
                int flag = 0;
                for (int l = 0; l < count; l++)
                {
                    int sum = 0;
                    for (int h = 0; h < n; h++)
                    {
                        if (nset[l][h] == 1)
                            sum += qlist[h] + loss;
                    }
                    if (sum > len + loss)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    mn = mn > count ? count : mn;
            }

            int NN = cnt;
            printf("%d ->", node);
            //将剩余木块作为下一木料的所有选取方法的输入
            Perm(node * 2, mlist, 0, 0, left, count + 1, nset, klist);
            printf("%d ->", node);
            //取当前木料的所对应的下一种木块的取法，每次取下一个木块，确保不重复取
            Perm(node * 2 + 1, list, level + 1, i + 1, m, count, set, klist);
        }
    }
    return;
}
/*
1000 100 250 500 650 1000 -1
*/
// printf("Point ID: %d\n", cnt);
// printf("level: %d\n    k: %d\n    m :%d\n", level, k, m);
// printf("list: ");
// for (int i = 0; i < n; i++)
//     printf("%d ", list[i]);
// puts("");
// printf("set: \n");
// for (int i = 0; i < Maxn; i++)
// {
//     for (int j = 0; j < Maxn; j++)
//         printf("%d ", set[i][j]);
//     puts("");
// }
// printf("nlist: ");
// for (int i = 0; i < n; i++)
//     printf("%d ", nlist[i]);
// puts("\n");
// for (int i = 1; i <= 195; i++)
//   printf("%d\n", i);

//freopen("Alogrithm3-1.out", "w", stdout);
