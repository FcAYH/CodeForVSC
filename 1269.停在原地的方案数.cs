/*
 * @lc app=leetcode.cn id=1269 lang=csharp
 *
 * [1269] 停在原地的方案数
 */

// @lc code=start
public class Solution
{
    const long Mod = 1000000007;
    public int NumWays(int steps, int arrLen)
    {
        arrLen = Math.Min(steps >> 1, arrLen - 1);
        long[,] A = new long[steps + 1, arrLen + 1];

        for (int i = 0; i <= arrLen; i++)
            A[1, i] = 1;

        for (int i = 1; i <= steps; i++)
            A[i, 0] = 1;

        for (int i = 2; i <= steps; i++)
        {
            for (int j = 1; j <= arrLen; j++)
            {
                A[i, j] += A[i, j - 1];
                for (int k = 1; k * (arrLen - 1) <= steps; k++)
                {
                    A[i, j] += 8
                }
            }
        }

        return A[steps, arrLen];
    }
}
// @lc code=end

