#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Inf 0x3f3f3f3f

//图
typedef struct Graphics
{

    int N_row, N_edge; //点数, 边数
    int **Map;         //邻接矩阵存图
    int *vis, *dis;
    void InitFromFile();
    int MST();
} Graphics;

//图的初始化:输入点和边的个数，同时输入边
void Graphics::InitFromFile()
{
    scanf("%d%d", &this->N_row, &this->N_edge);

    this->Map = (int **)malloc(sizeof(int *) * (N_row + 1));
    for (int i = 1; i <= N_row; i++)
        this->Map[i] = (int *)malloc(sizeof(int) * (N_row + 1));

    for (int i = 1; i <= N_row; i++)
    {
        for (int j = 1; j <= N_row; j++)
            this->Map[i][j] = 0;
    }

    for (int i = 1; i <= N_edge; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        this->Map[u][v] = w, this->Map[v][u] = w;
    }

    this->vis = (int *)malloc(sizeof(int) * (N_row + 1));
    this->dis = (int *)malloc(sizeof(int) * (N_row + 1));
}

//prime算法求最小生成树
int Graphics::MST()
{
    int ans = 0;
    //将vis和dis数组初始化
    for (int i = 1; i <= this->N_row; i++)
        this->vis[i] = 0, this->dis[i] = Inf;

    this->dis[1] = 0;

    //prim
    for (int i = 1; i <= this->N_row; i++)
    {

        int Min = Inf, id = 0;
        for (int j = 1; j <= this->N_row; j++)
        {
            if (!this->vis[j] && this->dis[j] < Min)
                Min = this->dis[j], id = j;
        }

        ans += this->dis[id];
        this->vis[id] = 1;
        printf("%d ", id);

        for (int j = 1; j <= this->N_row; j++)
        {
            if (this->Map[id][j] && this->dis[j] > this->Map[id][j])
                this->dis[j] = this->Map[id][j];
        }
    }

    return ans;
}

void Open_File()
{
    freopen("Map.map", "r", stdin);
    freopen("Ans.ans", "w", stdout);
}
void Close_File()
{
    fclose(stdin);
    fclose(stdout);
}

void Solve()
{
    Open_File();

    Graphics G;
    G.InitFromFile();

    printf("The Spanning tree has these points:\n");

    int ans = G.MST();

    printf("\nMST's valus is : %d\n", ans);

    Close_File();
}

int main()
{
    Solve();

    return 0;
}
/*
4 6
1 2 3
2 4 1 
3 4 2
1 3 5
2 3 2
1 4 6
*/
