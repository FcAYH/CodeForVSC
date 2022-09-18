/*
 * @lc app=leetcode.cn id=191 lang=csharp
 *
 * [191] 位1的个数
 */

// @lc code=start
public class Solution
{
    public int HammingWeight(uint n)
    {
        int Ans = 0;
        while (n != 0)
        {
            if ((n & 1) != 0)
                Ans++;

            n >>= 1;
        }

        return Ans;
    }
}
// @lc code=end

