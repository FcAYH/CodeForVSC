#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Maxn 101

char s[Maxn];
char Map[Maxn][Maxn];
int Maxd = 0;

//最大值函数
int w_max(int x, int y)
{
    return (x > y) ? x : y;
}

//树的结点
typedef struct TNode
{
    char data;
    int depth;
    TNode *lchild, *rchild;
    TNode *Insert(int pos, bool flag);
    void Print(int x, int y, int layers);
    void FindDepth();
} TNode;

//在 this节点添加后继，flag为 0 说明添加的是左孩子，为 1 则为右孩子
TNode *TNode::Insert(int pos, bool flag)
{
    TNode *Newp = (TNode *)malloc(sizeof(TNode));
    Newp->rchild = NULL, Newp->lchild = NULL;
    Newp->data = s[pos];
    Newp->depth = 0;

    (flag) ? this->rchild = Newp : this->lchild = Newp;

    return Newp;
}
//将节点信息输入到 Map数组中
void TNode::Print(int x, int y, int layers)
{

    int left, right; //左右孩子的x坐标
    layers--;
    int j = pow(2, layers); //孩子坐标偏移量

    if (this != NULL)
    {
        //printf("%c %d %d %d\n", this->data, y, x, layers);
        left = x - pow(2, layers);
        right = x + pow(2, layers);
        Map[y][x] = this->data;
        if (this->lchild)
        {
            for (int i = j; i > 0; i--)
                Map[y + 1][x - i] = '_';
            Map[y + 1][x] = '|';
            Map[y + 2][x - j] = '|';
        }

        if (this->rchild)
        {
            for (int i = j; i > 0; i--)
                Map[y + 1][x + i] = '_';
            Map[y + 1][x] = '|';
            Map[y + 2][x + j] = '|';
        }
        y += 3;

        this->lchild->Print(left, y, layers);  //左子树
        this->rchild->Print(right, y, layers); //右子树
    }
}
//计算树的深度
void TNode::FindDepth()
{
    Maxd = w_max(Maxd, this->depth);
    if (this->lchild != NULL)
    {
        this->lchild->depth = this->depth + 1;
        this->lchild->FindDepth();
    }

    if (this->rchild != NULL)
    {
        this->rchild->depth = this->depth + 1;
        this->rchild->FindDepth();
    }
}

//树结构体
typedef struct BiTree
{
    TNode *root;
    int depth;
    void Init();
    void Print();
    void CalcDepth();
} BiTree;

//树的初始化
void BiTree::Init()
{
    this->root = (TNode *)malloc(sizeof(TNode));
    this->root->lchild = NULL, this->root->rchild = NULL;
    this->root->data = s[1];
    this->depth = 0;
}
//树的输出
void BiTree::Print()
{
    this->root->Print(pow(2, this->depth), 0, this->depth);
}
//树的深度计算
void BiTree::CalcDepth()
{
    this->root->depth = 1;
    this->root->FindDepth();
}

//建树
void Dfs(TNode *p, int &pos)
{
    pos++;
    if (s[pos] != '#')
    {
        //新建节点的左孩子
        TNode *Nextp = p->Insert(pos, 0);
        Dfs(Nextp, pos);
    }

    pos++;
    if (s[pos] != '#')
    {
        //新建节点的右孩子
        TNode *Nextp = p->Insert(pos, 1);
        Dfs(Nextp, pos);
    }
}

void Solve()
{
    scanf("%s", s + 1);
    if (s[1] == '#')
        return;

    BiTree T;
    T.Init();

    int pos = 1;
    Dfs(T.root, pos);

    T.CalcDepth();
    T.depth = Maxd;

    T.Print();

    for (int i = 0; i < 3 * (T.depth - 1) + 1; i++)
    {
        for (int j = 0; j <= Maxn; j++)
            printf("%c", Map[i][j]);
        puts("");
    }
}

int main()
{
    Solve();

    return 0;
}
/*
ABDH##I##EJ##K##CFL##M##GN##O##

A#B#C##

AB#DE##F##CG###

AB##C##

ABC####
*/
