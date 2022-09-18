#include <stdio.h>
#include <stdlib.h>

int *A;

int ReadFromFile()
{
    char ch[20];
    printf("Please input the name of the file to read from: ");
    scanf("%s", ch);
    FILE *fp = fopen(ch, "r");

    int n;
    fscanf(fp, "%d", &n);

    A = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &A[i]);

    fclose(fp);

    return n;
}

void Swap(int a, int b)
{
    int t = A[a];
    A[a] = A[b], A[b] = t;
}

void Sort(int Size)
{
    for (int i = 0; i < Size - 1; i++)
        for (int j = i + 1; j < Size; j++)
            if (A[j] < A[i])
                Swap(j, i);
}

void WriteToFile(int Size)
{
    char ch[20];
    printf("Please input the name of the file to write to: ");
    scanf("%s", ch);
    FILE *fp = fopen(ch, "w");

    for (int i = 0; i < Size; i++)
    {
        fprintf(fp, "%6d", A[i]);
        if (i % 5 == 4)
            fprintf(fp, "\n");
    }
}

void Solve()
{
    int Size = 0;
    Size = ReadFromFile();
    Sort(Size);
    WriteToFile(Size);
}

int main()
{
    Solve();

    return 0;
}
