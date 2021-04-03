#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Maxn 101

int id = 0, flag = 0;
char s[Maxn];

//树的结点
typedef struct TNode
{
    char data;
    int depth;
    TNode *lchild, *rchild;
    TNode *Insert(int pos, bool flag);
    void FirstFind(char ch);
    void MidFind(char ch);
    void LastFind(char ch);
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
void TNode::FirstFind(char ch)
{
    id++;
    if (this->data == ch)
        printf("In the Preorder traversal, the id is: %d\n", id), flag = 1;
    if (this->lchild)
        this->lchild->FirstFind(ch);
    if (this->rchild)
        this->rchild->FirstFind(ch);
}
void TNode::MidFind(char ch)
{
    if (this->lchild)
        this->lchild->MidFind(ch);
    id++;
    if (this->data == ch)
        printf("In the Middle order traversal, the id is: %d\n", id), flag = 1;
    if (this->rchild)
        this->rchild->MidFind(ch);
}
void TNode::LastFind(char ch)
{
    if (this->lchild)
        this->lchild->LastFind(ch);
    if (this->rchild)
        this->rchild->LastFind(ch);
    id++;
    if (this->data == ch)
        printf("In the Postorder traversal, the id is: %d\n", id), flag = 1;
}

//树结构体
typedef struct BiTree
{
    TNode *root;
    int depth;
    void Init();
    void Find(char ch);
} BiTree;

//树的初始化
void BiTree::Init()
{
    this->root = (TNode *)malloc(sizeof(TNode));
    this->root->lchild = NULL, this->root->rchild = NULL;
    this->root->data = s[1];
    this->depth = 0;
}
void BiTree::Find(char ch)
{
    id = 0;
    this->root->FirstFind(ch); //先序遍历
    id = 0;
    this->root->MidFind(ch); //中序遍历
    id = 0;
    this->root->LastFind(ch); //后序遍历
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
    printf("Please input the tree: ");
    scanf("%s", s + 1);
    if (s[1] == '#')
        return;

    BiTree T;
    T.Init();

    int pos = 1;
    Dfs(T.root, pos);

    printf("Please input the char you want to find ('#' to exit): ");
    char ch[3];
    scanf("%s", ch);
    while (ch[0] != '#')
    {
        flag = 0;
        T.Find(ch[0]);
        if (!flag)
            printf("The %c Node is not find!\n", ch[0]);
        printf("Please input the char you want to find ('#' to exit): ");
        scanf("%s", ch);
    }
    printf("\nGoodbye\n");
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
