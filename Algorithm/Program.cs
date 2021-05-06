using System;
using System.Collections;
using System.Collections.Generic;

namespace Algorithm
{
    class Program
    {
        static void Main(string[] args)
        {
            IList<int> Ans = new List<int>();
            Ans.Add(1);

            for (int i = 1; i <= 10; i++)
                Ans.Add(i);

            foreach (int i in Ans)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine("Hello World!");
        }
    }
}
