/*
 * @lc app=leetcode.cn id=879 lang=csharp
 *
 * [879] 盈利计划
 */

// @lc code=start
public class Solution
{
    private const int Mod = (int)1e9 + 7;
    private int[,] A;
    public int ProfitableSchemes(int n, int minProfit, int[] group, int[] profit)
    {
        A = new int[n + 1, minProfit + 1];
        A[0, 0] = 1;

        for (int tasks = 0; tasks < group.Length; tasks++)
            for (int i = n; i >= group[tasks]; i--)
                for (int j = minProfit; j >= 0; j--)
                    A[i, j] = (A[i, j] + A[i - group[tasks], Math.Max(0, j - profit[tasks])]) % Mod;

        int Ans = 0;
        for (int i = 0; i <= n; i++)
            Ans = (Ans + A[i, minProfit]) % Mod;

        return Ans;
    }
}
// @lc code=end

