#include <stdio.h>

int main()
{
    int m;
    int i;
    int sum = 0;
    for (i = 1;; i++)
    {
        sum = sum + i * i * i;
        if (sum >= 1000000)
            break;
    }
    m = i - 1;
    printf("m = %d\n", m);
    return 0;
}
