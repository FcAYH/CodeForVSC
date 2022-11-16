using Solutions;
using System;
using System.Collections.Generic;

public class Entry
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(" ");
        (int n, int m, int start) = (int.Parse(input[0]), int.Parse(input[1]), int.Parse(input[2]));

        Graph graph = new Graph(n, m);
        for (int i = 0; i < m; i++)
        {
            input = Console.ReadLine().Split(" ");
            (int u, int v, int w) = (int.Parse(input[0]), int.Parse(input[1]), int.Parse(input[2]));
            graph.AddEdge(u, v, w);
        }

        int[] dis = Dijkstra.Solve(graph, start);

        foreach (var val in dis)
        {
            Console.WriteLine(val + " ");
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

4 6 1
0 1 2
0 2 5
1 2 2
0 3 4
2 3 1
3 1 2
*/
