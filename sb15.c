#include<stdio.h>

int main()
{
    int a[7],x;
    printf("输入数组6个元素的值。\n");
    for(int i=1;i<=6;i++) scanf("%d",&a[i]);
    printf("此链表各个结点的数据域为：");
    for(int i=1;i<=6;i++) printf("%d ",a[i]);
    printf("\n输入要删除的数据x: ");
    scanf("%d",&x);
    printf("删除后链表各个结点的数据域为：");
    for(int i=1;i<=6;i++) if(a[i]!=x) printf("%d ",a[i]);
}
/*
输入数组6个元素的值。
11 22 33 44 55 66
此链表各个结点的数据域为：11 22 33 44 55 66 
输入要删除的数据x: 33
删除后链表各个结点的数据域为：11 22 44 55 66 
*/