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

            Tuple<int, int> tuple = new Tuple<int, int>(1, 2);
            Tuple<int, int> tuple2 = new Tuple<int, int>(2, 1);


            Console.WriteLine(tuple.Equals(tuple2));
        }
    }
}
