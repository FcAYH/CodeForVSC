#include <stdio.h>
#include <string.h>

#define AC 0;
#define WA 1
#define ERROR -1

ifstream fout;
FILE *fin;
ofstream fscore, freport;

void quite(int score, const char *str)
{
    //cout << score << str;
    fscore << score;
    freport << str;
    fclose(fin);
    fout.close();
    fscore.close();
    freport.close();
    exit(0);
}

const int MAXN = 100000;
char str[MAXN];
int n, f[MAXN], st[MAXN];
int h[MAXN], to[MAXN], nx[MAXN], tot;
bool vis[MAXN];

void ad(int u, int v)
{
    nx[++tot] = h[u];
    h[u] = tot;
    to[tot] = v;
    nx[++tot] = h[v];
    h[v] = tot;
    to[tot] = u;
}

void dfs(int x)
{
    //cout << x << endl;
    vis[x] = 1;
    f[x] = 1;
    for (int i = h[x]; i; i = nx[i])
    {
        if (vis[to[i]])
            continue;
        dfs(to[i]);
        f[x] += f[to[i]];
        int tmp = f[to[i]];
        st[tmp] = st[n - tmp] = 1;
    }
}

int spj(FILE *input, FILE *user_output);

void close_file(FILE *f)
{
    if (f != NULL)
    {
        fclose(f);
    }
}

int main(int argc, char *args[])
{
    //cout <<"hwew";
    //fin.open(argv[1]);

    FILE *input = NULL, *user_output = NULL;
    int result;
    if (argc != 3)
    {
        printf("Usage: spj x.in x.out\n");
        return ERROR;
    }

    input = fopen(args[1], "r");
    user_output = fopen(args[2], "r");

    if (input == NULL || user_output == NULL)
    {
        printf("Failed to open output file\n");
        close_file(input);
        close_file(user_output);
        return ERROR;
    }

    result = spj(input, user_output);

    printf("result:%d\n", result);

    close_file(input);
    close_file(user_output);

    return result;

    fin = fopen(argv[1], "r");
    fout.open(argv[2]);
    fscore.open(argv[5]);
    freport.open(argv[6]);
}

int spj(FILE *input, FILE *user_output)
{
    fscanf(input, "%s", str + 1); //fin >> (str + 1);
    n = strlen(str + 1);
    //puts(str+1);
    int x, y, edge_cnt = 0;
    for (int i = 1; i < n; i++)
    {
        fout >> x;
        fout >> y;
        if (x == 0 || y == 0)
            quite(0, "not a tree");
        ad(x, y);
        edge_cnt++;
    }
    fout >> x;
    if (!fout.eof())
        quite(0, "not a tree");
    if (edge_cnt != n - 1)
    {
        quite(0, "not a tree1");
    }
    dfs(1);
    for (int i = 2; i <= n; i++)
        if (!vis[i])
        {
            quite(0, "not a tree2");
        }
    for (int i = 1; i <= n; i++)
    {
        //cout << i << " " << str[i]-'0' << " "<<st[i]<<endl;
        if (str[i] - '0' != (int)st[i])
        {

            quite(0, "ans is wrong");
        }
    }
    quite(10, "ans is correct");
}
