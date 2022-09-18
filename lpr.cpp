#include <stdio.h>

#define AC 0
#define WA 1
#define ERROR -1

int spj(FILE *input, FILE *user_output);

void close_file(FILE *f)
{
    if (f != NULL)
    {
        fclose(f);
    }
}

int main(int argc, char *args[])
{
    FILE *input = NULL, *user_output = NULL;
    int result;
    if (argc != 3)
    {
        printf("Usage: spj x.in x.out\n");
        return ERROR;
    }
    input = fopen(args[1], "r");
    user_output = fopen(args[2], "r");
    if (input == NULL || user_output == NULL)
    {
        printf("Failed to open output file\n");
        close_file(input);
        close_file(user_output);
        return ERROR;
    }

    result = spj(input, user_output);
    printf("result: %d\n", result);

    close_file(input);
    close_file(user_output);
    return result;
}

int spj(FILE *input, FILE *user_output)
{
    /*
    parameter: 
    - input，标程输入的文件指针
    - user_output，用户输出文件的指针
    return: 
    - 如果用户答案正确，返回AC
    - 如果用户答案错误返回WA
    - 如果主动捕获到自己的错误，如内存分配失败，返回ERROR
    请用户完成此函数.
    demo:
    int a, b;
    while(fscanf(f, "%d %d", &a, &b) != EOF){
        if(a -b != 3){
            return WA;
        }
    }
    return AC;
     */
}
