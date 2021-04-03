#include <stdio.h>
#include <stdlib.h>

#define MaxSize 200

//矩阵
typedef struct Matrix
{
    int *data;
} Matrix;

//初始化矩阵
void Matrix_Init(Matrix *M)
{
    M->data = (int *)malloc(MaxSize * sizeof(int));
    for (int i = 0; i <= MaxSize - 1; i++)
        M->data[i] = 0;
}

//建立杨辉三角
void Matrix_YangHui(Matrix *M, int n)
{
    int nowp = 0;
    M->data[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            //通过第i行第j列的元素，去推第i+1行第j列以及i+1行j+1列的元素，
            //这样写比常规的方式更简单。
            M->data[nowp + (i + 1)] += M->data[nowp], M->data[nowp + (i + 2)] += M->data[nowp];
            ++nowp;
        }
    }
}

//输出矩阵
void Matrix_Print(Matrix *M, int n)
{
    int nowp = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%4d", M->data[nowp++]);
        puts("");
    }
}

//释放内存
void Matrix_Free(Matrix *M)
{
    free(M->data);
}

void Solve()
{
    int n;
    printf("Please input an intger n:\n");
    scanf("%d", &n);

    Matrix M;
    Matrix_Init(&M);
    Matrix_YangHui(&M, n);
    Matrix_Print(&M, n);
    Matrix_Free(&M);
}

int main()
{
    Solve();

    system("pause");

    return 0;
}
