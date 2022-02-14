// #include <bits/stdc++.h>

// using namespace std;

// const int MAX_HEIGHT = 5;
// const int MAX_WIDTH = 500;

// char ans[MAX_HEIGHT][MAX_WIDTH];

// char table[10][5][5] = {
//     "XXX.",
//     "X.X.",
//     "X.X.",
//     "X.X.",
//     "XXX.",

//     "..X.",
//     "..X.",
//     "..X.",
//     "..X.",
//     "..X.",

//     "XXX.",
//     "..X.",
//     "XXX.",
//     "X...",
//     "XXX.",

//     "XXX.",
//     "..X.",
//     "XXX.",
//     "..X.",
//     "XXX.",

//     "X.X.",
//     "X.X.",
//     "XXX.",
//     "..X.",
//     "..X.",

//     "XXX.",
//     "X...",
//     "XXX.",
//     "..X.",
//     "XXX.",

//     "XXX.",
//     "X...",
//     "XXX.",
//     "X.X.",
//     "XXX.",

//     "XXX.",
//     "..X.",
//     "..X.",
//     "..X.",
//     "..X.",

//     "XXX.",
//     "X.X.",
//     "XXX.",
//     "X.X.",
//     "XXX.",

//     "XXX.",
//     "X.X.",
//     "XXX.",
//     "..X.",
//     "XXX."};

// void Solve()
// {
//     int n;
//     scanf("%d", &n);

//     char *str = new char[n + 1];
//     scanf("%s", str);

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < 5; j++)
//         {
//             for (int k = 0; k < 4; k++)
//             {
//                 ans[j][4 * i + k] = table[str[i] - '0'][j][k];
//             }
//         }
//     }

//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < n * 4 - 1; j++)
//         {
//             printf("%c", ans[i][j]);
//         }
//         puts("");
//     }
// }

// int main()
// {
//     Solve();

//     return 0;
// }

// /*
// XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
// X.X...X...X...X.X.X.X...X.....X.X.X.X.X
// X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
// X.X...X.X.....X...X...X.X.X...X.X.X...X
// XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
// */
// */

#include <stdio.h>
#include <string.h>
char p[105];
char ans[103][6][6]; // n个数 5*3
char print[6][444];  //转二维数组输出
int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", p);

    for (int i = 0; i < n; i++)
    {
        switch (p[i]) //绘图
        {
        case '0':
        {
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if (k == 2 && j != 1 && j != 5)
                        // printf("%c", '.');i8
                        ans[i][j][k] = '.';
                    else
                        // printf("%c", 'X');
                        ans[i][j][k] = 'X';
                }
                if (i != (n - 1))
                    ans[i][j][4] = '.';
            }
            break;
        }
        case '1':
        {
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if (k == 3)
                        ans[i][j][k] = 'X';
                    else
                        ans[i][j][k] = '.';
                }
                if (i != (n - 1))
                    ans[i][j][4] = '.';
            }
            break;
        }
        case '2':
        {
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if ((j == 2 && k != 3) || (j == 4 && k != 1))
                        ans[i][j][k] = '.';
                    else
                        // printf("%c", 'X');
                        ans[i][j][k] = 'X';
                }
                if (i != (n - 1))
                    ans[i][j][4] = '.';
            }
            break;
        }
        case '3':
        {
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if ((j == 2 && k != 3) || (j == 4 && k != 3))
                        ans[i][j][k] = '.';
                    else
                        // printf("%c", 'X');
                        ans[i][j][k] = 'X';
                }
                if (i != (n - 1))
                    ans[i][j][4] = '.';
            }
            break;
        }
        case '4':
        {
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if ((k == 2 && j != 3) || (k == 1 && (j == 4 || j == 5)))
                        ans[i][j][k] = '.';
                    else
                        // printf("%c", 'X');
                        ans[i][j][k] = 'X';
                }
                if (i != (n - 1))
                    ans[i][j][4] = '.';
            }
            break;
        }
        case '5':
        {
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if ((j == 2 && k != 1) || (j == 4 && k != 3))
                        ans[i][j][k] = '.';
                    else
                        // printf("%c", 'X');
                        ans[i][j][k] = 'X';
                }
                if (i != (n - 1))
                    ans[i][j][4] = '.';
            }
            break;
        }
        case '6':
        {
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if ((j == 2 && k != 1) || (j == 4 && k == 2))
                        ans[i][j][k] = '.';
                    else
                        // printf("%c", 'X');
                        ans[i][j][k] = 'X';
                }
                if (i != (n - 1))
                    ans[i][j][4] = '.';
            }
            break;
        }
        case '7':
        {
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if (j != 1 && k != 3)
                        ans[i][j][k] = '.';
                    else
                        // printf("%c", 'X');
                        ans[i][j][k] = 'X';
                }
                if (i != (n - 1))
                    ans[i][j][4] = '.';
            }
            break;
        }
        case '8':
        {
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if ((j == 2 && k == 2) || (j == 4 && k == 2))
                        ans[i][j][k] = '.';
                    else
                        // printf("%c", 'X');
                        ans[i][j][k] = 'X';
                }
                if (i != (n - 1))
                    ans[i][j][4] = '.';
            }
            break;
        }
        case '9':
        {
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if ((j == 2 && k == 2) || (j == 4 && k != 3))
                        ans[i][j][k] = '.';
                    else
                        // printf("%c", 'X');
                        ans[i][j][k] = 'X';
                }
                if (i != (n - 1))
                    ans[i][j][4] = '.';
            }
            break;
        }
        default:
            break;
        }

        //转二维
        // char table[10][5][5] = {
        //     "XXX.",
        //     "X.X.",
        //     "X.X.",
        //     "X.X.",
        //     "XXX.",
        //     "..X.",
        //     "..X.",
        //     "..X.",
        //     "..X.",
        //     "..X.",
        //     "XXX.",
        //     "..X.",
        //     "XXX.",
        //     "X...",
        //     "XXX.",
        //     "XXX.",
        //     "..X.",
        //     "XXX.",
        //     "..X.",
        //     "XXX.",
        //     "X.X.",
        //     "X.X.",
        //     "XXX.",
        //     "..X.",
        //     "..X.",
        //     "XXX.",
        //     "X...",
        //     "XXX.",
        //     "..X.",
        //     "XXX.",
        //     "XXX.",
        //     "X...",
        //     "XXX.",
        //     "X.X.",
        //     "XXX.",
        //     "XXX.",
        //     "..X.",
        //     "..X.",
        //     "..X.",
        //     "..X.",
        //     "XXX.",
        //     "X.X.",
        //     "XXX.",
        //     "X.X.",
        //     "XXX.",
        //     "XXX.",
        //     "X.X.",
        //     "XXX.",
        //     "..X.",
        //     "XXX."};
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            for (int k = 1; k <= 4; k++)
                printf("%c", ans[i][j][k]);
            puts("");
        }
        puts("");
    }

    for (int j = 1; j <= 5; j++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = 1; k <= 4; k++)
                print[j][4 * i + k] = ans[i][j][k];
        }
    }
    //输出二维
    for (int j = 1; j <= 5; j++)
    {
        for (int k = 1; k <= 4 * n - 1; k++)
        {
            printf("%c", print[j][k]);
            // printf("%d ", 0 + j);
        }
        printf("\n");
    }

    return 0;
}
