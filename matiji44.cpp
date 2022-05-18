#include <bits/stdc++.h>

using namespace std;

int x, y;

/*
xiaoMaGe
1: 2x + 2y;
2: 1x + 12y;
3: 0x + 22y;
gqs:
1: 0x + 22y;
2: 1x + 12y;
3: 2x + 2y;
*/

bool xiaoMaGe()
{
    bool OK = false;
    if (x >= 2 && y >= 2)
        x -= 2, y -= 2, OK = true;
    else if (x >= 1 && y >= 12)
        x -= 1, y -= 12, OK = true;
    else if (y >= 22)
        y -= 22, OK = true;

    return OK;
}

bool gqs()
{
    bool OK = false;
    if (y >= 22)
        y -= 22, OK = true;
    else if (x >= 1 && y >= 12)
        x -= 1, y -= 12, OK = true;
    else if (x >= 2 && y >= 2)
        x -= 2, y -= 2, OK = true;

    return OK;
}

int main()
{
    scanf("%d%d", &x, &y);

    while (true)
    {
        if (!xiaoMaGe())
        {
            printf("gqs");
            break;
        }

        if (!gqs())
        {
            printf("xmg");
            break;
        }
    }

    return 0;
}
