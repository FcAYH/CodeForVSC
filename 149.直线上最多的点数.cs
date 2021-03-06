using System;
/*
 * @lc app=leetcode.cn id=149 lang=csharp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
public class Solution
{
    Dictionary<Tuple<int, int>, int> dict;
    private int Gcd(int x, int y)
    {
        return (y == 0) ? x : Gcd(y, x % y);
    }
    public int MaxPoints(int[][] points)
    {
        int n = points.Length;

        if (n <= 2)
            return n;

        int Ans = 2;
        for (int i = 0; i < n - 1; i++)
        {
            dict = new Dictionary<Tuple<int, int>, int>();

            for (int j = i + 1; j < n; j++)
            {
                int x1 = points[j][0] - points[i][0];
                int y1 = points[j][1] - points[i][1];

                if (x1 <= 0)
                {
                    if (x1 == 0 && y1 < 0)
                        y1 = -y1;
                    else if (x1 < 0)
                    {
                        x1 = -x1; y1 = -y1;
                    }
                }

                int gcd = Gcd(Math.Abs(x1), Math.Abs(y1));
                x1 /= gcd; y1 /= gcd;

                Tuple<int, int> tuple = new Tuple<int, int>(x1, y1);
                if (!dict.ContainsKey(tuple))
                    dict.Add(tuple, 2);
                else
                    dict[tuple]++;

                foreach (int keyVal in dict.Values)
                    Ans = Math.Max(Ans, keyVal);
            }
        }

        return Ans;
    }
}

// @lc code=end

/*
[[1,1],[2,2],[3,3]]
[[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
[[1,1]]
[[1,1],[2,3]]
[[7,3],[19,19],[-16,3],[13,17],[-18,1],[-18,-17],[13,-3],[3,7],[-11,12],[7,19],[19,-12],[20,-18],[-16,-15],[-10,-15],[-16,-18],[-14,-1],[18,10],[-13,8],[7,-5],[-4,-9],[-11,2],[-9,-9],[-5,-16],[10,14],[-3,4],[1,-20],[2,16],[0,14]]
[[7,3],[19,19],[-16,3],[13,17],[-18,1],[-18,-17],[13,-3],[3,7],[-11,12],[7,19],[19,-12],[20,-18],[-16,-15],[-10,-15],[-16,-18],[-14,-1],[18,10],[-13,8],[7,-5],[-4,-9],[-11,2],[-9,-9],[-5,-16],[10,14],[-3,4],[1,-20],[2,16],[0,14],[-14,5],[15,-11],[3,11],[11,-10],[-1,-7],[16,7],[1,-11],[-8,-3],[1,-6],[19,7],[3,6],[-1,-2],[7,-3],[-6,-8],[7,1],[-15,12],[-17,9],[19,-9],[1,0],[9,-10],[6,20],[-12,-4],[-16,-17],[14,3],[0,-1],[-18,9],[-15,15],[-3,-15],[-5,20],[15,-14],[9,-17],[10,-14],[-7,-11],[14,9],[1,-1],[15,12],[-5,-1],[-17,-5],[15,-2],[-12,11],[19,-18],[8,7],[-5,-3],[-17,-1],[-18,13],[15,-3],[4,18],[-14,-15],[15,8],[-18,-12],[-15,19],[-9,16],[-9,14],[-12,-14],[-2,-20],[-3,-13],[10,-7],[-2,-10],[9,10],[-1,7],[-17,-6],[-15,20],[5,-17],[6,-6],[-11,-8]]
[[-14,5],[15,-11],[3,11],[11,-10],[-1,-7],[16,7],[1,-11],[-8,-3],[1,-6],[19,7],[3,6],[-1,-2],[7,-3],[-6,-8],[7,1],[-15,12],[-17,9],[19,-9],[1,0],[9,-10],[6,20],[-12,-4],[-16,-17],[14,3],[0,-1],[-18,9],[-15,15],[-3,-15],[-5,20],[15,-14],[9,-17],[10,-14],[-7,-11],[14,9],[1,-1],[15,12],[-5,-1],[-17,-5],[15,-2],[-12,11],[19,-18],[8,7],[-5,-3],[-17,-1],[-18,13],[15,-3],[4,18],[-14,-15],[15,8],[-18,-12],[-15,19],[-9,16],[-9,14],[-12,-14],[-2,-20],[-3,-13],[10,-7],[-2,-10],[9,10],[-1,7],[-17,-6],[-15,20],[5,-17],[6,-6],[-11,-8]]
[[0,-1],[-18,9],[-15,15],[-3,-15],[-5,20],[15,-14],[9,-17],[10,-14],[-7,-11],[14,9],[1,-1],[15,12],[-5,-1],[-17,-5],[15,-2],[-12,11],[19,-18],[8,7],[-5,-3],[-17,-1],[-18,13],[15,-3],[4,18],[-14,-15],[15,8],[-18,-12],[-15,19],[-9,16],[-9,14],[-12,-14],[-2,-20],[-3,-13],[10,-7],[-2,-10],[9,10],[-1,7],[-17,-6],[-15,20],[5,-17],[6,-6],[-11,-8]]
[[-3,-13],[10,-7],[-2,-10],[9,10],[-1,7],[-17,-6],[-15,20],[5,-17],[6,-6],[-11,-8]]
[[9,-17],[10,-14],[-7,-11],[14,9],[1,-1],[15,12],[-5,-1],[-17,-5],[15,-2],[-12,11],[19,-18],[8,7],[-5,-3],[-17,-1],[-18,13]]
[[0,-1],[-18,9],[-15,15],[-3,-15],[-5,20],[15,-14],[9,-17],[10,-14],[-7,-11],[14,9],[1,-1],[15,12],[-5,-1],[-17,-5],[15,-2],[-12,11],[19,-18],[8,7],[-5,-3],[-17,-1],[-18,13],[15,-3],[4,18],[-14,-15],[15,8]]
[[-5,-1],[-17,-5],[15,-2],[-12,11],[19,-18]]
[[15,-14],[15,12],[15,-2],[15,-3],[15,8]]

[[0,1],[0,0],[0,4],[0,-2],[0,-1],[0,3],[0,-4]]
*/
