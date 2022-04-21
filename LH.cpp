#include <bits/stdc++.h>

using namespace std;

const int MaxNodeCount = 64;

map<int, int> Tree;
int ans = 0;

void Dfs(int node, int sum)
{
    sum += Tree[node];

    int currentDepth = node / 10;
    int leftChild = currentDepth * 10 + node % 10;
    int rightChild = leftChild + 1;
    bool hasLeftChild = Tree.find(leftChild) == Tree.end();
    bool hasRightChild = Tree.find(rightChild) == Tree.end();
    if (!hasLeftChild && !hasRightChild)
    {
        // leaf
        ans += sum;
    }
    else
    {
        if (hasLeftChild)
            Dfs(leftChild, sum);
        if (hasRightChild)
            Dfs(rightChild, sum);
    }
}

void Solve()
{
    int n;
    int number[MaxNodeCount];

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &number[i]);
        Tree[number[i] / 10] = number[i] % 10;
    }

    Dfs(number[0] / 10, 0);
}

int main()
{
    Solve();

    return 0;
}

const int BUFFER_SIZE = 100;
char *recordString;
char *strtok(char *str, char *splits)
{
    if (str != NULL)
    {
        recordString = str;
    }

    if (*recordString == '\0')
        return NULL;

    int length = strlen(splits);

    int index = 0;
    char *returnChars = new char[BUFFER_SIZE];

    while (*recordString != '\0')
    {
        returnChars[index++] = *recordString;

        for (int i = 0; i < length; i++)
        {
            if (*recordString == splits[i])
            {
                returnChars[index] = '\0';
                break;
            }
        }

        recordString++;
    }

    return returnChars;
}
