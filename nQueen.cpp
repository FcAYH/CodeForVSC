
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#define MAXNUMBER 20

//判断当前得到的解向量是否满足问题的解
bool place_queen(int x[], int k)
{
    int i;
    for (i = 1; i < k; i++)
    {
        if ((x[i] == x[k]) || (abs(x[i] - x[k]) == abs(i - k)))
            return false;
    }

    return true;
}

//将结果简单信息打印到屏幕
void output_queens(int x[], int n)
{
    for (int i = 1; i <= n; i++)
        printf("%3d", x[i]);

    printf(" ");
}

//将结果详细信息写入文件
void output_queens(FILE *fp, int number, int x[], int n)
{
    fprintf(fp, "solution %d: ", number);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == x[i])
                fprintf(fp, "1  ");
            else
                fprintf(fp, "0  ");
        }
        fprintf(fp, " ");
    }
    fprintf(fp, " ");
}

/************************************************************************
 *  n后问题求解
 *  input  : n, the number of queens
 *  output : the vector of solution, X
 ************************************************************************/
int n_queens(FILE *fp, int n, int x[])
{
    int nCount = 0; //解个数
    int k = 1;      //先处理第1个皇后
    x[1] = 0;

    while (k > 0)
    {
        x[k] = x[k] + 1; //在当前列加1的位置开始搜索

        while (x[k] <= n && !place_queen(x, k)) //当前列位置是否满足条件
            x[k] = x[k] + 1;                    //不满足,继续搜索下一列位置

        if (x[k] <= n) //若存在满足条件的列
        {
            if (k == n) //是最后一个皇后，则得到一个最终解
            {
                //break;    //此处若break,则只能得到一个解
                nCount++;
                output_queens(x, n); //输出
                output_queens(fp, nCount, x, n);
            }
            else //否则，处理下一个皇后,即第 k+1 个皇后
            {
                k++;
                x[k] = 0;
            }
        }
        else //若不存在满足条件的列,则回溯
        {
            x[k] = 0; //第k个皇后复位为0
            k--;      //回溯到前一个皇后
        }
    }

    return nCount;
}

int main()
{
    int n = 8, x[MAXNUMBER] = {0};

    FILE *fp = fopen("8皇后问题的解.txt", "w");
    if (fp == NULL)
    {
        printf("can not wirte file!");
        exit(0);
    }

    printf("the queens are placed on the coloums : ");
    //求解并写入文件
    int nCount = n_queens(fp, n, x);
    printf("there are %d solutions! ", nCount);
    fclose(fp);
    getch();

    return 0;
}
