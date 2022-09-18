/*
 * @lc app=leetcode.cn id=461 lang=csharp
 *
 * [461] 汉明距离
 */

// @lc code=start
public class Solution
{
    public int HammingDistance(int x, int y)
    {
        int Ans = 0;

        for (int i = 0; i <= 30; i++)
        {
            if (((x ^ y) & (1 << i)) != 0)
                Ans++;
        }

        return Ans;
    }
}
// @lc code=end

