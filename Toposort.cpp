#include <bits/stdc++.h>

using namespace std;

class Edge
{
private:
    int to, next;

public:
    Edge() {}
    ~Edge() {}

    void To(int to) { this->to = to; };
    void Next(int next) { this->next = next; };
    int getTo() { return this->to; }
    int getNext() { return this->next; }
};

class Graphics
{
private:
    int num;
    int vertices, edges;
    int *head, *in;
    Edge *E;

public:
    Graphics(int n, int m) : num(0), vertices(n), edges(m)
    {
        head = new int[vertices + 1];
        in = new int[vertices + 1];
        E = new Edge[edges + 1];

        memset(head, 0, sizeof(head) * (vertices + 1));
        memset(in, 0, sizeof(in) * (vertices + 1));
    };
    ~Graphics()
    {
        delete[] head;
        delete[] in;
        delete[] E;
    }

    void add_edge();
    void Toposort();
};

inline void Graphics::add_edge()
{
    printf("Please input the No.%d edge:\n", this->num + 1);
    int u, v;
    scanf("%d%d", &u, &v);

    this->in[v]++;
    this->E[++num].Next(this->head[u]);
    this->E[num].To(v);
    this->head[u] = this->num;
}
void Graphics::Toposort()
{
    queue<int> Q;

    for (int i = 1; i <= this->vertices; i++)
        if (!this->in[i])
            Q.push(i);

    while (!Q.empty())
    {
        int st = Q.front();
        printf("%d ", st);
        Q.pop();

        for (int i = this->head[st]; i; i = this->E[i].getNext())
        {
            int qt = this->E[i].getTo();
            this->in[qt]--;
            if (!this->in[qt])
                Q.push(qt);
        }
    }

    puts("");
}

void Solve()
{
    printf("Please input the amount of the vertices and edges in the graph:\n");
    int n, m;
    scanf("%d%d", &n, &m);
    Graphics G(n, m);

    for (int i = 1; i <= m; i++)
        G.add_edge();

    G.Toposort();
}

int main()
{
    Solve();

    return 0;
}
/*
3 2
1 2 
1 3

10 11 
1 2
1 3
1 4
2 3
2 4
3 5
3 6
4 7
4 8
5 9
6 10
*/
