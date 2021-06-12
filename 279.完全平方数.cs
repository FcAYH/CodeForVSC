using System.Globalization;
/*
 * @lc app=leetcode.cn id=279 lang=csharp
 *
 * [279] 完全平方数
 */

// @lc code=start
public class Solution
{
    //private List<int> number = new List<int>();
    public int NumSquares(int n)
    {
        // for (int i = 1; i * i <= n; i++)
        //     number.Add(i * i);

        int[] A = new int[n + 1];
        Array.Fill(A, int.MaxValue);

        A[0] = 0;
        //foreach (int i in number)
        for (int i = 1; i * i <= n; i++)
        {
            for (int j = i * i; j <= n; j++)
                A[j] = Math.Min(A[j], A[j - i * i] + 1);
        }

        return A[n];
    }
}
// @lc code=end

