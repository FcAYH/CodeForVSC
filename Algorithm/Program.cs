using System;
using System.Collections;
using System.Collections.Generic;

namespace Algorithm
{
    class Program
    {
        static void Main(string[] args)
        {
            int temp = 0;
            for (int i = 1; i <= 7; i++)
                temp ^= i;

            Console.WriteLine(temp.ToString());
        }
    }
}
