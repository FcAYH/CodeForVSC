using Solutions;
using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Diagnostics;

public class Entry
{
    private static void Fun(int[] arr)
    {
        arr[0] = 10;
        arr[1] = 20;
    }

    public static void Main()
    {
        int[] arr = new int[2];

        Fun(arr);
        Console.WriteLine(arr[0] + " " + arr[1]);
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
