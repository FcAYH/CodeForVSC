#include <bits/stdc++.h>

using namespace std;

const int startYear = 2001;
const int startMonth = 1;
const int startDay = 22;

const int M[2][13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Solve()
{
    int Year, Month, Day;
    scanf("%d/%d/%d", &Year, &Month, &Day);

    bool flag = (!(Year % 4) && (Year % 100)) || (!(Year % 400));

    if (Day > M[flag][Month] || (Year < 2001) || (Year == 2001 && Month == 1 && Day < 22))
    {
        printf("Invalid");
        return;
    }
    else
    {
        int timelong = 0;

        if (Year == startYear)
        {
            if (Month == startMonth)
                timelong += Day - startDay;
            else
            {
                timelong += 9;
                for (int i = startMonth + 1; i < Month; i++)
                    timelong += M[flag][Month];
                timelong += Day;
            }
        }
        else
        {
            timelong += 343;
            for (int i = startYear + 1; i < Year; i++)
            {
                flag = (!(i % 4) && (i % 100)) || (!(i % 400));
                timelong += flag ? 366 : 365;
            }
            flag = (!(Year % 4) && (Year % 100)) || (!(Year % 400));
            for (int i = 1; i < Month; i++)
                timelong += M[flag][i];
            timelong += Day;
        }

        printf("%d", timelong);
    }
}
int main()
{
    Solve();

    return 0;
}
