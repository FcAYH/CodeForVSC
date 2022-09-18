#include <stdio.h>

void Solve()
{
    char Person[31] = "";

    printf("The original circle is (+:papandom,  @:christian);\n");

    int cnt = 0, nowp = 1, tag = 1;

    while (1)
    {
        if (nowp == 9)
        {
            Person[tag] = '+';
            //printf("<%d>\n", tag);
            nowp = 1, cnt++;
            if (cnt == 15)
                break;
            while (Person[tag] == '+')
            {
                tag++;
                if (tag == 31)
                    tag = 1;
            }
        }
        else
        {
            nowp++;
            tag++;
            if (tag == 31)
                tag = 1;
            while (Person[tag] == '+')
            {
                tag++;
                if (tag == 31)
                    tag = 1;
            }
        }
    }

    for (int i = 1; i <= 30; i++)
        if (Person[i] != '+')
            printf("@ ");
        else
            printf("+ ");
}

int main()
{
    Solve();

    return 0;
}

//@ @ @ @ + + + + + @ @ + @ @ @ + @ + + @ @ + + + @ + + @ @ +
//@ @ @ @ + + + + + @ @ + @ @ @ + @ + + @ @ + @ + @ + + @ @ +
