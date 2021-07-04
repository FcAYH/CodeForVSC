#include <bits/stdc++.h>

using namespace std;

// 归并排序（C-递归版）
void merge_sort_recursive(int arr[], int reg[], int start, int end)
{
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}
void merge_sort(int arr[], const int len)
{
    int reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}

void Solve()
{
    int n;
    scanf("%d", &n);

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    merge_sort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    delete[] arr;
}

int main()
{
    Solve();

    return 0;
}
