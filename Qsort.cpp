#include <cstdio>
#include <iostream>
#include <ctime>

using namespace std;

struct Range
{
    int start, end;
    Range(int s = 0, int e = 0) { start = s, end = e; }
};

template <typename T>
void quick_sort(T arr[], const int len)
{
    if (len <= 0)
        return;
    Range r[len];
    int p = 0;
    r[p++] = Range(0, len - 1);
    while (p)
    {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        T mid = arr[range.end];
        int left = range.start, right = range.end - 1;
        while (left < right)
        {
            while (arr[left] < mid && left < right)
                left++;
            while (arr[right] >= mid && left < right)
                right--;
            std::swap(arr[left], arr[right]);
        }
        if (arr[left] >= arr[range.end])
            std::swap(arr[left], arr[range.end]);
        else
            left++;
        r[p++] = Range(range.start, left - 1);
        r[p++] = Range(left + 1, range.end);
    }
}

void Solve()
{
    int *array;
    int length;

    scanf("%d", &length);
    array = new int[length + 1];
    for (int i = 0; i < length; i++)
        scanf("%d", &array[i]);

    //clock_t start = clock();
    quick_sort(array, length);
    //clock_t end = clock();

    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
}

int main()
{
    Solve();

    return 0;
}
