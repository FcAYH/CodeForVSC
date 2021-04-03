#include <stdio.h>

int Year1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Year2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char Eng[13][13] = {
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "Jone",
    "July",
    "August",
    "September",
    "October",
    "November",
    "Devember"};

void PRINT(int Month, int Day)
{
    //printf("%d\n", Month);
    if (Day == 1 || Day == 11 || Day == 21)
    {
        printf("Dated this %dst day of %s", Day, Eng[Month]);
    }
    else if (Day == 2 || Day == 12 || Day == 22)
    {
        printf("Dated this %dnd day of %s", Day, Eng[Month]);
    }
    else if (Day == 3 || Day == 13 || Day = 23)
    {
        printf("Dated this %drd day of %s", Day, Eng[Month]);
    }
    else
    {
        printf("Dated this %dth day of %s", Day, Eng[Month]);
    }
}

int check(int Month, int Year, int Day)
{
    Year += 1900;
    if (Month < 0 || Month > 12)
        return 0;
    if (!(Year % 400) || (!(Year % 4) && (Year % 100)))
    {
        if (Day < 0 || Day > Year2[Month])
            return 0;
    }
    else
    {
        if (Day < 0 || Day > Year1[Month])
            return 0;
    }
    return 1;
}

void Solve()
{
    int mm, dd, yy;
    printf("Enter date (mm/dd/yy):");
    scanf("%d/%d/%d", &mm, &dd, &yy);
    if (!check(mm, yy, dd))
    {
        printf("Input error!\n");
        return;
    }
    PRINT(mm, dd);
    printf(", 19%.2d.\n", yy);
    //printf("Dated this %d" "st/nd/rd/th" " day of " "January/February/.../December");
    //printf("19%.2d.\n")
}

int main()
{
    Solve();

    return 0;
}
//7/19/96
