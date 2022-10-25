#include <bits/stdc++.h>

using namespace std;

const int MAX_VALUE = 1000;
const float PROPORTION = 0.5;

int translate_to_int(char *arg)
{
    int val = 0;
    int length = strlen(arg);
    for (int i = 0; i < length; i++)
    {
        val = val * 10 + arg[i] - '0';
    }

    return val;
}

int main(int argc, char **argv)
{
    FILE *fileA = fopen("MatA.txt", "w");
    FILE *fileB = fopen("MatB.txt", "w");

    srand(time(0));

    int a = translate_to_int(argv[1]); // row1
    int b = translate_to_int(argv[2]); // col1 = row2
    int c = translate_to_int(argv[3]); // col2

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (rand() % 10 < (int)(PROPORTION * 10))
            {
                continue;
            }

            int val = rand() % MAX_VALUE;
            if (val != 0)
            {
                fprintf(fileA, "%d,%d   %d\n", i, j, val);
            }
        }
    }

    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (rand() % 10 < (int)(PROPORTION * 10))
            {
                continue;
            }

            int val = rand() % MAX_VALUE;
            if (val != 0)
            {
                fprintf(fileB, "%d,%d   %d\n", i, j, val);
            }
        }
    }

    fclose(fileA);
    fclose(fileB);
}
