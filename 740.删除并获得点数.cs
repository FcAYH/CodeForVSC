/*
 * @lc app=leetcode.cn id=740 lang=csharp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
public class Solution
{
    public int DeleteAndEarn(int[] nums)
    {
        int max = 0;
        foreach (int i in nums)
            max = Math.Max(i, max);

        int[] vis = new int[max + 1];
        int[] Ans = new int[max + 1];

        foreach (int i in nums)
            vis[i]++;

        Ans[1] = 1 * vis[1];
        for (int i = 2; i <= max; i++)
            Ans[i] = Math.Max(Ans[i - 1], Ans[i - 2] + i * vis[i]);

        return Ans[max];
    }
}
// @lc code=end

