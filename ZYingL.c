#include <stdio.h>
#include <math.h>

int main()
{
    char op, ch;
    float n, m;
    printf("Please enter the expression:\n");
    while (1)
    {
        scanf("%f %c%f", &n, &op, &m);
        if (op != '+' && op != '-' && op != '*' && op != '/')
        {
            printf("Unknown operator!\n");
        }

        switch (op)
        {
        case '+':
            printf("%f + %f = %f\n", n, m, n + m);
            break;
        case '-':
            printf("%f - %f = %f\n", n, m, n - m);
            break;
        case '*':
            printf("%f * %f = %f\n", n, m, n * m);
            break;
        case '/':
            if (fabs(m) < 1e-7)
            {
                printf("Division by zero!\n");
                break;
            }
            else
            {
                printf("%f / %f = %f\n", n, m, n / m);
                break;
            }
        }
        printf("Do you want to continue(Y/N or y/n)?");
        char ch[2];
        scanf("%s", ch);
        //printf("%c", ch);
        if (ch[0] == 'n' || ch[0] == 'N')
        {
            return 0;
        }
        else if (ch[0] == 'Y' || ch[0] == 'y')
        {
            printf("Please enter the expression:\n");
        }
    }
}
