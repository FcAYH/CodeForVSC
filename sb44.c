#include <stdio.h>

struct
{
    int num;
    char name[10];
    char tp;
    union /*共用体类型*/
    {
        int inclass;
        char position[10];
    } job; /*共用体变量*/
} person[2];

void Solve()
{
    int n;
    printf("请输入个人信息的人数：\n");
    scanf("%d", &n);

    printf("请输入个人信息：\n");
    for (int i = 1; i <= n; i++)
    {
        printf("第%d个人\n", i);
        scanf("%d %s %c", &person[i - 1].num, &person[i - 1].name, &person[i - 1].tp);
        if (person[i - 1].tp == 's')
            scanf("%d", &person[i - 1].job.inclass);
        else
            scanf("%s", &person[i - 1].job.position);
    }

    printf("\n编号    姓名    类型    班级/职位\n");
    for (int i = 1; i <= n; i++)
    {
        if (person[i - 1].tp == 's')
            printf("%d\t%s\t%c\t%d\n", person[i - 1].num, person[i - 1].name, person[i - 1].tp, person[i - 1].job.inclass);
        else
            printf("%d\t%s\t%c\t%s\n", person[i - 1].num, person[i - 1].name, person[i - 1].tp, person[i - 1].job.position);
    }
}

int main()
{
    Solve();

    return 0;
}
