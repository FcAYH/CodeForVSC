#include <stdio.h>
void bubble_sort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
int main()
{
    int n;
    scanf("%d", &n);

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bubble_sort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

/*
5
6 4 3 1 2
*/
