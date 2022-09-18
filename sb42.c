#include <stdio.h>

void Solve()
{
    int id, Time, fee;
    int FEE[4] = {0, 28, 48, 68};
    int TIME[4] = {0, 200, 500, 800};
    scanf("%d,%d,%d", &id, &Time, &fee);

    if ((id < 1 || id > 3) || (Time < 0) || (fee < 0))
        printf("Error");
    else
    {
        if (fee >= 200 & fee < 300)
            fee = 300 + fee - 200;
        else if (fee >= 300 && fee < 500)
            fee = 500 + fee - 300;
        else
            fee = 800 + fee - 500;
        fee -= FEE[id];

        float remind = (float)fee;
        if (Time > TIME[id])
        {
            remind -= (float)(Time - TIME[id]) * 0.25;
        }
        printf("remainder=%.2f", remind);
    }
}

int main()
{
    Solve();

    return 0;
}
