using Solutions;
using System;
using System.Collections.Generic;
using System.Text;

public class Entry
{
    public static void Main()
    {
        uint uu = (1u << 31);
        Console.WriteLine(uu);
    }
}

/*
6,0,8,2,1,5
0 1 2 3 4 5

0 1 2 5 6 8
1 4 3 5 0 2

[9,8,1,0,1,9,4,0,4,1]

2 2 1
0 1 2

1 2 2
2 0 1
2 1 0
*/
