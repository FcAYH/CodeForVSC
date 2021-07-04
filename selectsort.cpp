#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b) //交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int arr[], int len)
{
    int i, j;

    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++) //走訪未排序的元素
            if (arr[j] < arr[min])    //找到目前最小值
                min = j;              //紀錄最小值
        swap(&arr[min], &arr[i]);     //做交換
    }
}

void Solve()
{
    int n;
    scanf("%d", &n);

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    selection_sort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    Solve();

    return 0;
}
/*
5
6 3 2 1 4
*/
