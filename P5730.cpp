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
    // for (int i = 1; i <= n; i++)
    //   scanf("%c", &p[i]);
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
                if (p[i] != p[n - 1])
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
                if (p[i] != p[n - 1])
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
                if (p[i] != p[n - 1])
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
                if (p[i] != p[n - 1])
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
                if (p[i] != p[n - 1])
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
                if (p[i] != p[n - 1])
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
                if (p[i] != p[n - 1])
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
                if (p[i] != p[n - 1])
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
                if (p[i] != p[n - 1])
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
                if (p[i] != p[n - 1])
                    ans[i][j][4] = '.';
            }
            break;
        }
        default:
            break;
        }
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
        }
        printf("\n");
    }
    return 0;
}

/* for (int j = 1; j <= 5; j++)
   {
       for (int i = 1; i <= n; i++)
       {
           for (int k = 1; k <= 4; k++)
           {
               printf("%c", ans[i][j][k]);
           }
       }
       printf("\n");
   }*/
// print[j][4 * i + k] = table[p[i] - '0'][j][k];
/*  {
      if (k == 1)
          print[j][4 * i + 1] = 'a' + i; // ans[i][j][k];
      if (k == 2)

      if (k == 3)
          print[j][4 * i + 3] = ans[i][j][k];
      if (k == 4)
          print[j][4 * i + 4] =5 ans[i][j][k];
  }*/
// }
// else
// {
//     for (int k = 1; k <= 3; k++)
//     {
//         print[j][4 * i + k] = table[i][j][k];
//     }
// }
