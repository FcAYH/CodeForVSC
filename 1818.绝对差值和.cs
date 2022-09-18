using System;
/*
 * @lc app=leetcode.cn id=1818 lang=csharp
 *
 * [1818] 绝对差值和
 */

// @lc code=start
public class Solution
{
    private const int Mod = 1000000007;
    public int MinAbsoluteSumDiff(int[] nums1, int[] nums2)
    {
        int n = nums1.Length;
        int Ans = 0;
        int maxDif = 0, position = 0;

        for (int i = 0; i < n; i++)
        {
            int tempVal = Math.Abs(nums1[i] - nums2[i]);
            if (tempVal > maxDif)
            {
                maxDif = tempVal;
                position = i;
            }
            Ans = (Ans + tempVal) % Mod;
        }

        //Console.Write("{0}\n", Ans);

        for (int i = 0; i < n; i++)
        {
            int newNumber = Math.Abs(nums1[i] - nums2[position]);
            if (newNumber < maxDif)
            {
                Ans = (Ans - maxDif + newNumber) % Mod;
                maxDif = newNumber;
            }
        }

        return Ans % Mod;
    }
}
// @lc code=end

