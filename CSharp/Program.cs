using Solutions;
using System;
using System.Collections.Generic;
using System.Text;

public class Entry
{
    public struct Vector
    {
        public float a, b, c;
        public Vector(float a, float b, float c)
        {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        public override string ToString()
        {
            return $"({a}, {b}, {c})";
        }
    }
    public static void AddInt(List<int> intList)
    {
        for (int i = 0; i < 10; i++)
            intList.Add(i);
    }

    public static void ModifyList(List<Vector> list1, List<Vector> list2)
    {
        List<Vector> temp = new List<Vector>();
        list2.Clear();

        for (int i = 0; i < list1.Count; i++)
        {
            var vec = list1[i];
            temp.Add(vec);
            list2.Add(vec);
        }

        list1.Clear();
        list1.AddRange(temp);
    }

    public static void Main()
    {
        List<Vector> list = new List<Vector>();
        List<Vector> secList = new List<Vector>();

        list.Add(new Vector(1, 2, 3));
        list.Add(new Vector(2.3f, 2.13f, 5.3f));

        ModifyList(list, secList);

        Console.WriteLine($"list Count: {list.Count}, sec Count: {secList.Count}");
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

4 6 1
0 1 2
0 2 5
1 2 2
0 3 4
2 3 1
3 1 2
*/
