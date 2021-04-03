#include <stdio.h>
#include <string.h>

void Solve()
{
    printf("请输入四个数字字符：");
    char ch[20];
    scanf("%s", ch);

    int len = strlen(ch);
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        if (ch[i] >= '0' && ch[i] <= '9')
            num = num * 10 + ch[i] - '0';
        else
        {
            printf("有非数字字符！");
            return;
        }
    }
    printf("你输入的数值+1后为%d\n", num + 1);
}

int main()
{
    Solve();

    return 0;
}
