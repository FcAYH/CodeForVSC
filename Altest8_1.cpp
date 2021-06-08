#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define N 5
#define BIGNUM 1e9

struct HeapNode
{
    int v;
    int level;
    int bound;
    int route[N + 1];
};

void InsertHeap(HeapNode b[], HeapNode x, int &length);
void DeleteHeap(HeapNode b[], int &length);
void Tsp(int C[N][N], int pbound);
int RowMinExcept(int C[N][N], int row, int col);
int SiSum(int C[N][N], HeapNode temp);
int RowMinTwo(int C[N][N], int row);
bool Contain(HeapNode temp, int node);
int SjSum(int C[N][N], HeapNode temp);

HeapNode heap[100];
int heapLength = 0;
int level = 0;

int main()
{
    int C[N][N], upbound = 0;
    for (int i = 0; i < N; i++)
    {
        C[i][i] = BIGNUM;
        for (int j = i + 1; j < N; j++)
        {
            scanf("%d", &C[i][j]);
            C[j][i] = C[i][j];
        }
    }

    int k = N - 1;
    int i = 0;
    int max = BIGNUM;
    int visited[N];
    int row;

    for (int j = 0; j < N; j++)
        visited[j] = 0;

    while (k)
    {
        for (int j = 0; j < N; j++)
        {
            if (j == i | visited[j])
                continue;
            if (C[i][j] < max)
            {
                max = C[i][j];
                row = j;
            }
        }

        upbound += max;
        visited[i] = 1;
        i = row;
        k--;
        max = BIGNUM;
    }
    upbound += C[row][0];

    Tsp(C, upbound);

    return 0;
}

void InsertHeap(HeapNode b[], HeapNode x, int &length)
{
    int i;
    for (i = length + 1; i > 1; i = i / 2)
    {
        if (x.bound >= b[i / 2].bound)
            break;
        else
            b[i] = b[i / 2];
    }

    b[i] = x;
    length += 1;
}

void DeleteHeap(HeapNode b[], int &length)
{
    int i;
    b[1] = b[length];
    HeapNode temp = b[1];
    b[length].bound = BIGNUM;

    for (int i = 2; i < length; i *= 2)
    {
        if (b[i].bound > b[i + 1].bound)
            i++;
        if (temp.bound <= b[i].bound)
            break;
        b[i / 2] = b[i];
    }

    i = i / 2;
    b[i] = temp;
    length -= 1;
}

int RowMinExcept(int C[N][N], int row, int col)
{
    int min = BIGNUM;
    for (int j = 0; j < N; j++)
    {
        if (j == col)
            continue;
        if (C[row][j] < min)
            min = C[row][j];
    }

    return min;
}

int SiSum(int C[N][N], HeapNode temp)
{
    int level = temp.level;
    int sum = RowMinExcept(C, temp.route[0] - 1, temp.route[1] - 1) +
              RowMinExcept(C, temp.route[level] - 1, temp.route[level - 1] - 1);

    return sum;
}

int RowMinTwo(int C[N][N], int row)
{
    int minOne = BIGNUM;
    int minTwo = 0;
    int col;

    for (int j = 0; j < N; j++)
    {
        if (C[row][j] < minOne)
        {
            minOne = C[row][j];
            col = j;
        }
    }

    minTwo = RowMinExcept(C, row, col);

    return minOne + minTwo;
}

bool Contain(HeapNode temp, int node)
{
    int level = temp.level;

    for (int i = 0; i <= level; i++)
    {
        if (temp.route[i] == node)
            return true;
    }

    return false;
}

int SjSum(int C[N][N], HeapNode temp)
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!Contain(temp, i))
            sum = sum + RowMinTwo(C, i - 1);
    }

    return sum;
}

void Tsp(int C[N][N], int pbound)
{
    HeapNode rootNode;
    rootNode.v = 0;
    rootNode.level = 0;
    rootNode.route[0] = 1;
    rootNode.bound = SjSum(C, rootNode) / 2.0;

    InsertHeap(heap, rootNode, heapLength);

    while (heapLength > 0)
    {
        HeapNode temp;
        temp = heap[1];
        level = temp.level;

        DeleteHeap(heap, heapLength);

        if (level == N)
        {
            for (int i = 0; i <= N; i++)
            {
                printf("%d", temp.route[i]);
            }
            printf("\n%d", temp.v);
            return;
        }
        else
        {
            if ((level == N - 1) && (C[temp.route[level] - 1][temp.route[0] - 1] != BIGNUM))
            {
                temp.route[level + 1] = temp.route[0];
                float lb = temp.v + C[temp.route[level] - 1][temp.route[0] - 1];

                if (lb < pbound)
                {
                    HeapNode node;
                    node.v = lb;
                    node.bound = lb;

                    for (int i = 0; i <= level + 1; i++)
                        node.route[i] = temp.route[i];
                    node.level = level + 1;

                    InsertHeap(heap, node, heapLength);
                    pbound = lb;
                }
            }
            else
            {
                for (int j = 1; j <= N; j++)
                {
                    if ((C[temp.route[level] - 1][j - 1] != BIGNUM) && !Contain(temp, j))
                    {
                        temp.route[level + 1] = j;
                        temp.level = level + 1;

                        float lb = ((temp.v + C[temp.route[level] - 1][j - 1]) * 2 + SiSum(C, temp) + SjSum(C, temp)) / 2;

                        if (lb <= pbound)
                        {
                            HeapNode node;
                            node.v = temp.v + C[temp.route[level] - 1][j - 1];
                            node.bound = lb;

                            for (int i = 0; i <= level; i++)
                                node.route[i] = temp.route[i];
                            node.route[level + 1] = j;
                            node.level = level + 1;

                            InsertHeap(heap, node, heapLength);
                        }
                    }
                }
            }
        }
    }
}
