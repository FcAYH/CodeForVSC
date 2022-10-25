using Solutions;
using System;
using System.Collections.Generic;

public class Entry
{
    public static void Main()
    {
        Console.WriteLine("Enter:");

        int n = int.Parse(Console.ReadLine());

        string[] keyWords = new string[n];
        for (int i = 0; i < n; i++)
        {
            keyWords[i] = Console.ReadLine();
        }

        ACAutomaton ac = new ACAutomaton(keyWords);


        string input = Console.ReadLine();
        bool[] result = ac.Query(input);

        for (int i = 0; i < result.Length; i++)
        {
            Console.WriteLine(keyWords[i] + " occurs? ---> " + result[i]);
        }
    }
}

/*
4
as
acd
edf
sde
acasdedf

5
a
bb
aa
abaa
abaaa
abaaabaa
*/
