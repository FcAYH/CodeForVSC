#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Maxlen 200
#define MaxLine 100
#define Maxn 200

char Text[MaxLine][Maxn];

typedef struct KEY
{
    char ch;
    char s[20];
} KEY;

KEY Key[200];

void ReadFromFile()
{
    FILE *fp = fopen("text.compressed", "r");

    int NowL = 1;
    while (fgets(Text[NowL], Maxlen, fp) != NULL)
        NowL++;
}

void GetKey()
{
    int Tline = 0;
    for (int i = i; i <= MaxLine; i++)
    {
        if (Text[i][0] = '-')
        {
            Tline = i;
            break;
        }
    }
}

void Solve()
{
    ReadFromFile();

    GetKey();
}

int main()
{
    Solve();

    return 0;
}
