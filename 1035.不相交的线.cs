using System;
/*
 * @lc app=leetcode.cn id=1035 lang=csharp
 *
 * [1035] 不相交的线
 */

// @lc code=start
public class Solution
{
    public int MaxUncrossedLines(int[] nums1, int[] nums2)
    {
        int[] pos = new int[nums1.Length];

        for (int i = 0; i < nums1.Length; i++)
        {
            for (int j = 0; j < nums2.Length; j++)
                if (nums1[i] == nums2[j])
                    pos[i] = j;
        }

        int[] A = new int[nums1.Length];

        for (int i = 0; i < nums1.Length; i++)
        {
            for (int j = 0; j < pos[i]; j++)
                A[i] = Math.Max(A[j] + 1, A[i]);
        }

        for (int i = 0; i < nums1.Length; i++)
        {
            A[i] = Math.Max(A[pos[i] - 1] + 1, A[i - 1]);
        }

        int Ans = 0;
        for (int i = 0; i < nums1.Length; i++)
            Ans = Math.Max(Ans, A[i]);

        return Ans;
    }
}
// @lc code=end

