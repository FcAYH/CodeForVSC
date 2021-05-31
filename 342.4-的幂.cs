/*
 * @lc app=leetcode.cn id=342 lang=csharp
 *
 * [342] 4的幂
 */

// @lc code=start
public class Solution
{
    public bool IsPowerOfFour(int n)
    {
        return (n > 0) && ((n & (n - 1)) == 0) && ((n & 1431655765) != 0);
    }
}
// @lc code=end

//1010101010101010101010101010100
