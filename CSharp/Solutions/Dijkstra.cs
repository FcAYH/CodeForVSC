namespace Solutions;

public class Graph
{
    public int VertexCount => _vertexCount;
    public int EdgeCount => _edgeCount;

    private int _vertexCount;
    private int _edgeCount;
    private List<(int to, int val)>[] _edges;

    public Graph(int n, int m)
    {
        _vertexCount = n;
        _edgeCount = m;
        _edges = new List<(int to, int val)>[_vertexCount];
        for (int i = 0; i < _vertexCount; i++)
            _edges[i] = new List<(int to, int val)>();
    }

    public void AddEdge(int start, int end, int value)
    {
        _edges[start].Add((end, value));
    }

    public List<(int to, int val)> GetEdges(int start)
    {
        if (start < 0 || start >= _vertexCount)
            return null;

        return _edges[start];
    }
}

public class Dijkstra
{
    private static int[] _distance;
    private static bool[] _visit;

    private const int INF = 0x3f3f3f3f;

    public static int[] Solve(Graph g, int start)
    {
        _distance = new int[g.VertexCount];
        _visit = new bool[g.VertexCount];

        Array.Fill<int>(_distance, INF);
        _distance[start] = 0;

        for (int i = 0; i < g.VertexCount; i++)
        {
            int current = 0, minDis = INF;
            for (int j = 0; j < g.VertexCount; j++)
            {
                if (!_visit[j] && _distance[j] < minDis)
                {
                    current = j;
                    minDis = _distance[j];
                }
            }
            _visit[current] = false;

            foreach ((int to, int val) in g.GetEdges(current))
            {
                _distance[to] = Math.Min(_distance[to], _distance[current] + val);
            }
        }

        return _distance;
    }

    private Dijkstra() { }
}
/*
Main:

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
*/
