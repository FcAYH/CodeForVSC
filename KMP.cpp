#include <stdio.h>
#include <string.h>

#define Maxn 200

//求t1的next数组
void MakeNext(char Next[], char t1[])
{
    int k = 0, length = strlen(t1 + 1);
    for (int i = 2; i <= length; i++)
    {
        while (k > 0 && t1[k + 1] != t1[i])
            k = Next[k];
        if (t1[k + 1] == t1[i])
            k++;
        Next[i] = k;
    }
}

//KMP算法以及替换过程
void KMP(char s[], char t1[], char t2[], char Next[])
{
    char Ans[Maxn * 2] = "";
    int k = 0, cnt = 0;
    int len1 = strlen(s + 1), len2 = strlen(t1 + 1), len3 = strlen(t2 + 1);

    for (int i = 1; i <= len1; i++)
    {
        Ans[++cnt] = s[i];
        while (k > 0 && t1[k + 1] != s[i])
            k = Next[k];
        if (t1[k + 1] == s[i])
            k++;
        if (k == len2)
        {
            cnt -= len2;
            //替换
            for (int j = cnt + 1; j <= cnt + len3; j++)
                Ans[j] = t2[j - cnt];
            cnt = cnt + len3;
        }
    }

    printf("This is the sting after changing: \n");
    printf("%s\n", Ans + 1);
}

//在s中找t1，并替换成t2
char FindAndChange(char s[], char t1[], char t2[])
{
    char Next[Maxn];
    MakeNext(Next, t1);
    KMP(s, t1, t2, Next);
}

void print_welcome_desk()
{
    printf("This program can find string t1 from the Main string and replace it by string t2\n");
    printf("You can input \"exit\" to exit from the program");
}
void print_goodbye_desk()
{
    printf("Goodbye\n");
}

void Solve()
{
    print_welcome_desk();

    while (1)
    {
        char s[Maxn], t1[Maxn], t2[Maxn];

        printf("Please input the Main string:\n");
        scanf("%s", s + 1);

        if (s[1] == 'e' && s[2] == 'x' && s[3] == 'i' && s[4] == 't')
            break;

        printf("Please input string t1:\n");
        scanf("%s", t1 + 1);

        printf("Please input string t2:\n");
        scanf("%s", t2 + 1);

        FindAndChange(s, t1, t2);
        puts("");
    }
    print_goodbye_desk();
}

int main()
{
    Solve();

    return 0;
}

/*
adaewfsgresdswea
a
b

fwuwhfwjdsfkfwuehfwen
fw 
a

urhgenjeirurwhndweurbdxow
ur 
hee
*/
