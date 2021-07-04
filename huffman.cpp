#include <bits/stdc++.h>

using namespace std;

typedef struct Tree
{
    struct Tree *left;
    struct Tree *right;
    int data;
} Tree;

Tree *create(int *a, int n)
{ //对数组 a 进行实现哈夫曼树 a 中存放的为权值， n 为数组的长度
    Tree *tree;
    Tree **b;
    int i, j;
    b = malloc(sizeof(Tree) * n); //动态一维数组的申请来保存权值
    for (i = 0; i < n; i++)
    {
        b[i] = malloc(sizeof(Tree));
        b[i]->data = a[i];
        b[i]->left = b[i]->right = NULL;
    }
    //创建哈夫曼树
    for (i = 1; i < n; i++)
    {
        int small1 = -1, small2; //small1指向权值最小，small2是第二小，其初始指向分别是数组的前两个元素
                                 //注意前两个元素并不一定是最小的和第二小的
        //下面一个 for 循环是让small1指向第一个权值，small2指向第二个权值
        for (j = 0; j < n; j++)
        {
            if (b[j] != NULL && small1 == -1)
            {
                small1 = j;
                continue;
            }
            if (b[j] != NULL)
            {
                small2 = j;
                break;
            }
        }
        //接下来就是对数组剩下的权值逐个与small1、small2比较，找出最小与第二小的权值
        for (j = small2; j < n; j++)
        {
            if (b[j] != NULL)
            {
                if (b[j]->data < b[small1]->data)
                {
                    small2 = small1;
                    small1 = j;
                }
                else if (b[small2]->data > b[j]->data)
                {
                    small2 = j;
                }
            }
        }

        //由两个最小权值建立新树，tree 指向根节点
        tree = malloc(sizeof(Tree));
        tree->data = b[small1]->data + b[small2]->data;
        tree->left = b[small1];
        tree->right = b[small2];

        //以下两步是用于重复执行
        b[small1] = tree;
        b[small2] = NULL;
    }

    free(b);
    return tree;
}

//打印哈夫曼树
void print(Tree *tree)
{
    if (tree)
    {
        printf("%d ", tree->data);
        if (tree->left && tree->right)
        {
            printf("(");
            print(tree->left);
            if (tree->right)
                printf(",");
            print(tree->right);
            printf(")");
        }
    }
}

//获得哈夫曼树的带权路径长度
int getWeight(Tree *tree, int len)
{
    if (!tree)
        return 0;
    if (!tree->left && !tree->right) //访问到叶子结点
        return tree->data * len;
    return getWeight(tree->left, len + 1) + getWeight(tree->right, len + 1); //访问到非叶子结点
}

//哈夫曼编码
void getCoding(Tree *tree, int len)
{
    if (!tree)
        return;
    static int a[20]; //定义静态数组a，保存每个叶子的编码，数组长度至少是树深度减一
    int i;
    if (!tree->left && !tree->right)
    {
        printf(" %d  的哈夫曼编码为：", tree->data);
        for (i = 0; i < len; i++)
            printf("%d", a[i]);
        printf("\n");
    }
    else
    { //访问到非叶子结点时分别向左右子树递归调用，并把分支上的0、1编码保存到数组a ，的对应元素中，向下深入一层时len值增1
        a[len] = 0;
        getCoding(tree->left, len + 1);
        a[len] = 1;
        getCoding(tree->right, len + 1);
    }
}

//哈夫曼解码
void Decoding(Tree *tree)
{
    printf("请输入要解码的字符串\n");
    char ch[100]; //输入的待解码的字符串
    gets(ch);
    int i;
    int num[100]; //用于保存字符串对应的0 1 编码对应的节点
    Tree *cur;
    for (i = 0; i < strlen(ch); i++)
    {
        if (ch[i] == '0')
            num[i] = 0;
        else
            num[i] = 1;
    }

    if (tree)
    {
        i = 0;
        while (i < strlen(ch))
        {
            cur = tree;
            while (cur->left && cur->right)
            {

                if (num[i] == 0)
                    cur = cur->left;
                else
                    cur = cur->right;
                i++;
            }
            printf("%d", cur->data);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Tree *tree = create(a, n);
    print(tree);
    printf("\n哈夫曼树的权值为：");
    printf("%d\n", getWeight(tree, 0));
    getCoding(tree, 0);
    printf("解码时请参照上方编码\n");
    Decoding(tree);
}
