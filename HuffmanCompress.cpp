#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Maxn 200
#define MaxLen 200
#define MaxLine 100

char Text[MaxLine][Maxn];

char Key[Maxn][Maxn];

typedef struct TNode
{
    int val;
    char ch;
    TNode *lchild;
    TNode *rchild;
    void dfs(char s[], int pos);
} TNode;

TNode root;

void TNode::dfs(char s[], int pos)
{
    if (this->lchild == NULL && this->rchild == NULL)
    {
        for (int i = 0; i < pos; i++)
            Key[(int)this->ch][i] = s[i];
    }
    else
    {
        if (this->lchild != NULL)
        {
            s[pos] = '0';
            this->lchild->dfs(s, pos + 1);
        }
        if (this->rchild != NULL)
        {
            s[pos] = '1';
            this->rchild->dfs(s, pos + 1);
        }
    }
}

int len = 0;
typedef struct HNode
{
    TNode V;
} HNode;
typedef struct Heap
{
    HNode *h;
    int len;
    void Init();
    void Insert(TNode p);
    void Delete();
    int Empty();
} Heap;

void Heap::Init()
{
    this->len = 0;
    this->h = (HNode *)malloc(sizeof(HNode) * Maxn * 4);
}
void swap(HNode *a, HNode *b)
{
    HNode t = *a;
    *a = *b, *b = t;
}
void Heap::Insert(TNode p)
{
    this->h[++this->len].V = p;
    int si = 1, ilen = this->len;
    while (ilen >= 1 && si)
    {
        if (this->h[ilen >> 1].V.val > this->h[ilen].V.val)
            swap(&this->h[ilen], &this->h[ilen >> 1]);
        else
            si = 0;
        ilen >>= 1;
    }
}
void Heap::Delete()
{
    this->h[1] = this->h[this->len];
    this->len--;
    int t, si = 1, ilen = 1;
    while ((ilen << 1) <= this->len && si)
    {
        if (this->h[ilen].V.val > this->h[ilen << 1].V.val || this->h[ilen].V.val > this->h[ilen << 1 | 1].V.val)
        {
            if (this->h[ilen << 1].V.val > this->h[ilen << 1 | 1].V.val && (ilen << 1 | 1) <= this->len)
                t = ilen << 1 | 1;
            else
                t = ilen << 1;
            swap(&this->h[ilen], &this->h[t]);
            ilen = t;
        }
        else
            si = 0;
    }
}
int Heap::Empty()
{
    return (this->h[1].V.val == 0) ? 1 : 0;
}

int ReadFromFile()
{
    printf("Please input the name of the file to compress: ");
    char ch[20];
    scanf("%s", ch);

    FILE *fp = fopen(ch, "r");

    int NowL = 1;
    while (fgets(Text[NowL], MaxLen, fp) != NULL)
        NowL++;

    fclose(fp);
    return NowL;
}

int Alpha[200];

void MakeCount(int Line, Heap *H)
{
    for (int i = 1; i <= Line; i++)
    {
        int length = strlen(Text[i]);
        for (int j = 0; j < length; j++)
            Alpha[Text[i][j]]++;
    }

    for (int i = 1; i < 200; i++)
    {
        if (Alpha[i])
        {
            TNode p;
            p.ch = (char)i;
            p.val = Alpha[i];
            p.lchild = NULL, p.rchild = NULL;
            H->Insert(p);
        }
    }
}

void BuildTree(Heap *H)
{
    root = H->h[1].V;
    while (!H->Empty())
    {
        HNode a, b;
        a = H->h[1];
        H->Delete();
        b = H->h[1];
        H->Delete();

        TNode p;
        p.val = a.V.val + b.V.val;
        p.ch = ' ';
        p.lchild = &a.V;
        p.rchild = &b.V;
        root = p;
        H->Insert(p);
    }
}

void Compress(int Line)
{
    FILE *fp = fopen("text.compressed", "w");

    for (int i = 1; i <= 200; i++)
    {
        if (Key[i][0] == '0' || Key[i][0] == '1')
            fprintf(fp, "%d %s\n", i, Key[i]);
    }
    fprintf(fp,"-\n");
    for (int i = 1; i <= Line; i++)
    {
        int length = strlen(Text[i]);
        for (int j = 0; i < length; j++)
            fprintf(fp, "%s", Key[Text[i][j]]);
        fprintf(fp, "\n");
    }
}

void Solve()
{
    int Line = ReadFromFile();

    Heap H;
    H.Init();

    MakeCount(Line, &H);

    BuildTree(&H);

    char s[10];
    strcpy(s, "");
    root.dfs(s, 0);

    Compress(Line);
}

int main()
{
    Solve();

    return 0;
}
