using System;
using System.Collections;
namespace CodeForVSC
{
    class Program
    {

        public static void Calc()
        {
            string[] s = Console.ReadLine().Split(' ');
            Console.WriteLine(s[0] + ' ' + s[1]);
            Console.ReadKey();
        }
    }
}
