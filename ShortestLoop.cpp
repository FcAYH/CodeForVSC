#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Maxn 101
#define Inf 0x3f3f3f3f

//图
typedef struct Graph
{
    int N_vertex, N_edge; //点数，边数
    int Map[Maxn][Maxn];  //存图
    int Way[Maxn][Maxn];  //存路径
    void Init();          //初始化加读入数据
    void Floyd();         //Floyd算法加输出
} Graph;

//图的初始化加读入数据
void Graph::Init()
{
    printf("Please input the amount of vertexs and edges: ");
    scanf("%d%d", &this->N_vertex, &this->N_edge);
    memset(this->Map, 0x3f, sizeof(this->Map));

    printf("Please input each edge:\n");
    for (int i = 1; i <= this->N_edge; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        this->Map[u][v] = w;
    }

    for (int i = 1; i <= this->N_vertex; i++)
        for (int j = 1; j <= this->N_edge; j++)
            this->Way[i][j] = j;
}

//Floyd算法加输出
void Graph::Floyd()
{
    for (int k = 1; k <= this->N_vertex; k++)
    {
        for (int i = 1; i <= this->N_vertex; i++)
        {
            for (int j = 1; j <= this->N_vertex; j++)
            {
                if (this->Map[i][k] + this->Map[k][j] < this->Map[i][j])
                {
                    this->Map[i][j] = this->Map[i][k] + this->Map[k][j];
                    this->Way[i][j] = this->Way[i][k];
                }
            }
        }
    }

    int Min = Inf, id = 0;
    for (int i = 1; i <= this->N_vertex; i++)
        if (this->Map[i][i] < Min)
            Min = this->Map[i][i], id = i;

    printf("The shortest loop weighs: %d\n", Min);
    printf("This is the loop: \n    ");
    printf("%d -> ", id);
    int nowp = this->Way[id][id];
    while (nowp != id)
    {
        printf("%d -> ", nowp);
        nowp = this->Way[nowp][id];
    }
    printf("%d\n", id);
}

void Solve()
{
    Graph G;
    G.Init();
    G.Floyd();
}

int main()
{
    Solve();

    return 0;
}
/*
3 3
1 2 3
2 3 2
3 1 4

7 10
1 2 2
2 3 3
2 5 10
5 1 4
3 6 1
6 5 2
3 4 9
4 7 8
7 2 2
4 2 7

8 12
1 2 2
1 7 2
2 3 11
2 4 10
3 4 16
3 8 9
5 1 4
5 6 1
6 3 7
7 6 8
8 7 9
8 4 20


*/
