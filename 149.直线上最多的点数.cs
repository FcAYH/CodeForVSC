/*
 * @lc app=leetcode.cn id=149 lang=csharp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
public class Solution
{
    Dictionary<Pair<int, int>, bool> dict;
    private int Gcd(int x, int y)
    {
        return (y == 0) ? x : Gcd(y, x % y);
    }

    public int MaxPoints(int[][] points)
    {
        int Ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                int x1 = (points[j][0] - points[i][0]);
                int y1 = (points[j][1] - points[j][1]);
                int gcd = Gcd(x1, y1);
                x1 /= gcd; y1 /= gcd;

                if (!dict.ContainsKey((x1, y1)))
                {
                    dict.Add((x1, y1), true);

                    int tempCount = 0;
                    for (int k = j + 1; k < n; k++)
                    {
                        int x2 = (points[k][0] - points[j][0]);
                        int y2 = (points[k][1] - points[j][1]);

                        if (x1 * y2 == x2 * y1)
                            tempCount++;
                    }
                }

                Ans = Math.Max(Ans, tempCount);
            }
        }
    }

        return Ans;
    }
}
// @lc code=end

