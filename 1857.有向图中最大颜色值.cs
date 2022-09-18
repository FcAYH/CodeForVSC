/*
 * @lc app=leetcode.cn id=1857 lang=csharp
 *
 * [1857] 有向图中最大颜色值
 */

// @lc code=start
public class Solution
{
    struct Edge
    {
        public int to, next;
    };
    Edge[] E;

    int num = 0;
    int[] head;
    private void AddEdge(int x, int y)
    {
        E[++num].next = head[x];
        E[num].to = y;
        head[x] = num;
    }
    int flag = 0;
    int[] vis;

    public int LargestPathValue(string colors, int[][] edges)
    {
        if (edges.Length == 0)
            return 1;

        int pNum = colors.Length;
        int[] In = new int[pNum];

        E = new Edge[edges.Length * 2];
        head = new int[pNum];

        for (int i = 0; i < edges.Length; i++)
        {
            AddEdge(edges[i][0], edges[i][1]);
            In[edges[i][1]]++;
        }

        //toposort
        Queue<int> queue = new Queue<int>();

        for (int i = 0; i < pNum; i++)
            if (In[i] == 0)
                queue.Enqueue(i);

        int pTopo = 0;
        int[] topo = new int[pNum];

        while (queue.Count != 0)
        {
            int st = queue.Dequeue();
            topo[pTopo++] = st;

            for (int i = head[st]; i != 0; i = E[i].next)
            {
                int qt = E[i].to;

                if (--In[qt] == 0)
                    queue.Enqueue(qt);
            }
        }

        if (pTopo != pNum)
            return -1;

        int[,] A = new int[pNum, 26];
        int Ans = 0;

        for (int i = 0; i < pNum; i++)
            A[i, colors[i] - 'a'] = 1;

        for (int i = 0; i <= 25; i++)
        {
            for (int j = 0; j < pNum; j++)
            {
                int st = topo[j];
                for (int k = head[topo[j]]; k != 0; k = E[k].next)
                {
                    int qt = E[k].to;

                    A[qt, i] = Math.Max(A[qt, i], A[st, i] + ((colors[qt] - 'a' == i) ? 1 : 0));
                    Ans = Math.Max(Ans, A[qt, i]);
                }
            }
        }

        return Ans;
    }
}
// @lc code=end

