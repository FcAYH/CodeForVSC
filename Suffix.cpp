
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Size 205 //表达式最大长度

char s[Size]; //用来储存初始中缀表达式

typedef struct Stack //栈 - 用顺序表实现
{
    char *arrayc;
    int *arrayi;
    int top; //栈顶
} Stack;

//栈的初始化，flag=0则仅创建字符数组,flag=1则仅创建整型数组
void Stack_Init(Stack *S, int flag)
{
    if (!flag)
    {
        S->arrayc = (char *)malloc(sizeof(char) * Size);
        S->arrayi = NULL;
    }
    else
    {
        S->arrayi = (int *)malloc(sizeof(int) * Size);
        S->arrayc = NULL;
    }

    S->top = 0;
}

//释放空间
void Stack_Free(Stack *S, int flag)
{
    if (!flag)
        free(S->arrayc);
    else
        free(S->arrayi);
}

//将中缀表达式转为后缀表达式
void Make_Suffix(Stack *stack1, Stack *stack2, int length)
{
    for (int i = 1; i <= length; i++)
    {

        if (s[i] >= '0' && s[i] <= '9')
            stack1->arrayc[++stack1->top] = s[i];
        else
        {
            if (s[i] != ')')
            {
                if (stack2->arrayc[stack2->top] == '(' || stack2->top == 0)
                    stack2->arrayc[++stack2->top] = s[i];
                else
                {
                    if (s[i] == '+' || s[i] == '-')
                    {
                        while (stack2->arrayc[stack2->top] != '(' && stack2->top >= 1)
                            stack1->arrayc[++stack1->top] = stack2->arrayc[stack2->top--];
                        stack2->arrayc[++stack2->top] = s[i];
                    }
                    else if (s[i] == '*' || s[i] == '/')
                    {
                        while ((stack2->arrayc[stack2->top] == '*' || stack2->arrayc[stack2->top] == '/' || stack2->arrayc[stack2->top] == '^') && stack2->top >= 1)
                            stack1->arrayc[++stack1->top] = stack2->arrayc[stack2->top--];
                        stack2->arrayc[++stack2->top] = s[i];
                    }
                    else
                        stack2->arrayc[++stack2->top] = s[i];
                }
            }
            else
            {
                while (stack2->arrayc[stack2->top] != '(' && stack2->top >= 1)
                {
                    stack1->arrayc[++stack1->top] = stack2->arrayc[stack2->top];
                    stack2->top--;
                }
                stack2->top--;
            }
        }
    }
    while (stack2->top)
    {
        stack1->arrayc[++stack1->top] = stack2->arrayc[stack2->top--];
    }
}

//快速幂
int Quick_pow(int a, int k)
{
    int ret = a;
    k--;
    while (k > 0)
    {
        if (k & 1)
            ret *= a;
        a = a * a;
        k >>= 1;
    }
    return ret;
}

//计算后缀表达式
void Calc__Expression(Stack *stack1, Stack *Cstack)
{
    for (int i = 1; i <= stack1->top; i++)
        printf("%c ", stack1->arrayc[i]);
    puts("");
    for (int i = 1; i <= stack1->top; i++)
    {
        if (stack1->arrayc[i] >= '0' && stack1->arrayc[i] <= '9')
            Cstack->arrayi[++Cstack->top] = stack1->arrayc[i] - '0';
        else
        {
            int num1 = Cstack->arrayi[Cstack->top--];
            int num2 = Cstack->arrayi[Cstack->top--];
            switch (stack1->arrayc[i])
            {
            case '+':
            {
                Cstack->arrayi[++Cstack->top] = num2 + num1;
                break;
            }
            case '-':
            {
                Cstack->arrayi[++Cstack->top] = num2 - num1;
                break;
            }
            case '*':
            {
                Cstack->arrayi[++Cstack->top] = num2 * num1;
                break;
            }
            case '/':
            {
                Cstack->arrayi[++Cstack->top] = num2 / num1;
                break;
            }
            case '^':
            {
                Cstack->arrayi[++Cstack->top] = Quick_pow(num2, num1);
            }
            }
            for (int j = 1; j <= Cstack->top; j++)
                printf("%d ", Cstack->arrayi[j]);
            for (int j = i + 1; j <= stack1->top; j++)
                printf("%c ", stack1->arrayc[j]);
            puts("");
        }
    }
    puts("");
}

//处理单目运算符
void Make_NewS()
{
    char News[Size + 100] = "";
    int length = strlen(s + 1);
    int nowp = 0;
    for (int i = 1; i <= length; i++)
    {

        if (s[i] == '(' && (s[i + 1] == '-' || s[i + 1] == '+') && s[i + 2] >= '0' && s[i + 2] <= '9' && s[i + 3] == ')')
        {
            News[++nowp] = '(';
            News[++nowp] = '0';
            News[++nowp] = s[i + 1];
            News[++nowp] = s[i + 2];
            News[++nowp] = ')';
            i = i + 3;
        }
        else
            News[++nowp] = s[i];
    }

    int len = strlen(News + 1);
    for (int i = 1; i <= len; i++)
        s[i] = News[i];
}

void Print_welcome_desk()
{
    printf("欢迎使用本计算器：\n");
    printf("    1. 本计算器支持 + - * / ^ 五种运算方式，并且支持括号;\n");
    printf("    2. 当输入 +x 或 -x 时(即使用单目运算符 + - 时)，请用括号括起，即：3+(+1),2*(-1);\n");
    printf("    3. 请保证您输入的算式在数学运算法则下是正确的;\n");
    printf("    4. 若您想退出，请输入'exit' (不包含单引号).\n");
}
void Print_goodbye_desk()
{
    printf("Goodbye\n");
}

void Solve()
{
    Print_welcome_desk();

    while (1)
    {
        scanf("%s", s + 1);
        if (s[1] == 'e' && s[2] == 'x' && s[3] == 'i' && s[4] == 't')
            break;

        Stack stack1;
        Stack stack2;
        Stack Cstack;

        Stack_Init(&stack1, 0);
        Stack_Init(&stack2, 0);
        Stack_Init(&Cstack, 1);

        Make_NewS();

        int length = strlen(s + 1);

        Make_Suffix(&stack1, &stack2, length);

        Calc__Expression(&stack1, &Cstack);
    }

    Print_goodbye_desk();
}

int main()
{
    Solve();

    system("pause");

    return 0;
}
/*
8-(3+2*6)/5+4

1+2^3-(5^4+9)

5*2-1*(9+8)^3

9*9*9*9*9

(-2)+3*(-6)+(+7)-9
*/
