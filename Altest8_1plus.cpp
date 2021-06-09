#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define N 15
#define BIGNUM 1e9

int n;
struct HeapNode
{
    int v;
    int level;
    int bound;
    int route[N + 1];
};

void InsertHeap(HeapNode b[], HeapNode x, int &length);
void DeleteHeap(HeapNode b[], int &length);
void Tsp(int **C, int pbound);
int RowMinExcept(int **C, int row, int col);
int SiSum(int **C, HeapNode temp);
int RowMinTwo(int **C, int row);
bool Contain(HeapNode temp, int node);
int SjSum(int **C, HeapNode temp);

HeapNode heap[100];
int heapLength = 0;
int level = 0;

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

    for (i = 2; i < length; i *= 2)
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

int RowMinExcept(int **C, int row, int col)
{
    int min = BIGNUM;
    for (int j = 0; j < n; j++)
    {
        if (j == col)
            continue;
        if (C[row][j] < min)
            min = C[row][j];
    }

    return min;
}

int SiSum(int **C, HeapNode temp)
{
    int level = temp.level;
    int sum = RowMinExcept(C, temp.route[0] - 1, temp.route[1] - 1) + RowMinExcept(C, temp.route[level] - 1, temp.route[level - 1] - 1);

    return sum;
}

int RowMinTwo(int **C, int row)
{
    int minOne = BIGNUM;
    int minTwo = 0;
    int col;

    for (int j = 0; j < n; j++)
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

int SjSum(int **C, HeapNode temp)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!Contain(temp, i))
            sum = sum + RowMinTwo(C, i - 1);
    }

    return sum;
}

void Tsp(int **C, int pbound)
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

        if (level == n)
        {
            for (int i = 0; i <= n; i++)
            {
                printf("%d ", temp.route[i]);
            }
            printf("\n%d", temp.v);
            return;
        }
        else
        {
            if ((level == n - 1) && (C[temp.route[level] - 1][temp.route[0] - 1] != BIGNUM))
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
                for (int j = 1; j <= n; j++)
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

int main()
{
    int upbound = 0;

    int **C;
    scanf("%d", &n);
    C = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        C[i] = new int[n + 1];

    for (int i = 0; i < n; i++)
    {
        C[i][i] = BIGNUM;
        for (int j = i + 1; j < n; j++)
        {
            scanf("%d", &C[i][j]);
            C[j][i] = C[i][j];
        }
    }

    int k = n - 1;
    int i = 0;
    int max = BIGNUM;
    int visited[n];
    int row;

    for (int j = 0; j < n; j++)
        visited[j] = 0;

    while (k)
    {
        for (int j = 0; j < n; j++)
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

/*
4 8 6 5 3 2 10 8 7 3

20
487 975 636 836 688 546 411 748 199 302 808 945 34 631 462 644 551 401 128 203 268 533 102 906 424 871 173 256 450 7 283 80 266 315 451 327 960 612 128 509 206 3 417 554 576 776 293 857 928 998 583 44 25 274 95 696 825 962 360 933 390 159 20 76 923 29 110 323 742 904 513 498 482 2 643 276 333 83 375 244 711 778 226 190 925 932 116 993 260 224 654 387 150 984 61 135 571 574 696 144 720 807 840 66 99 794 862 466 195 510 570 758 20 519 683 363 672 887 702 191 861 276 656 460 611 943 977 336 751 805 397 645 697 354 210 16 947 278 975 864 881 903 995 988 335 979 109 176 170 136 285 334 247 380 913 426 868 780 478 961 818 771 359 754 160 873 675 23 670 558 735 426 583 900 803 320 35 440 697 926 613 375 339 77 227 635 486 491 786 587 
1444
*/
