using System;
/*
 * @lc app=leetcode.cn id=1486 lang=csharp
 *
 * [1486] 数组异或操作
 */

// @lc code=start
public class Solution
{
    public int XorOperation(int n, int start)
    {
        int ans = start;
        for (int i = 1; i < n; i++)
            ans ^= start + 2 * i;
        return ans;
    }
}
// @lc code=end

