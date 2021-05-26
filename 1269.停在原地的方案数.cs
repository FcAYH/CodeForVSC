/*
 * @lc app=leetcode.cn id=1269 lang=csharp
 *
 * [1269] 停在原地的方案数
 */

// @lc code=start
public class Solution
{
    const int Mod = 1000000007;
    public int NumWays(int steps, int arrLen)
    {
        arrLen = Math.Min(arrLen, steps / 2 + 1);
        int[,] A = new int[2, arrLen + 1];

        int flag = 0;
        A[0, 0] = 1;
        for (int i = 1; i <= steps; i++)
        {
            for (int j = 0; j < arrLen; j++)
            {
                if (j == 0)
                    A[flag ^ 1, j] = (A[flag, 1] + A[flag, 0]);
                else if (j == arrLen - 1)
                    A[flag ^ 1, j] = (A[flag, j - 1] + A[flag, j]);
                else
                    A[flag ^ 1, j] = (((A[flag, j - 1] + A[flag, j + 1]) % Mod) + A[flag, j]);

                A[flag ^ 1, j] %= Mod;
            }
            flag ^= 1;
        }

        return A[flag, 0];
    }
}
// @lc code=end

