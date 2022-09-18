using System;
using System.Windows.Forms;
namespace program
{
    class price
    {
        static void Calc()
        {
            string[] s = new string[2];
            s = Console.ReadLine().Split(' ');
            Console.WriteLine(s[0] + ' ' + s[1]);
            MessageBox.Show(s);
            Console.ReadKey();
        }
        static void Main(string[] args)
        {
            CodeForVSC.Program.Calc();
            // price.Calc();
            Console.WriteLine("Hello World!");
            Console.ReadKey();
        }
    }
}


