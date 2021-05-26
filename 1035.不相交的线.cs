using System;
/*
 * @lc app=leetcode.cn id=1035 lang=csharp
 *
 * [1035] 不相交的线
 */

// @lc code=start
public class Solution
{
    int[,] A;
    public int MaxUncrossedLines(int[] nums1, int[] nums2)
    {
        A = new int[nums1.Length, nums2.Length];

        for (int i = 0; i < nums1.Length; i++)
            A[i, 0] = (nums1[i] == nums2[0]) ? 1 : ((i == 0) ? 0 : A[i - 1, 0]);

        for (int i = 0; i < nums2.Length; i++)
            A[0, i] = (nums1[0] == nums2[i]) ? 1 : ((i == 0) ? 0 : A[0, i - 1]);

        for (int i = 1; i < nums1.Length; i++)
        {
            for (int j = 1; j < nums2.Length; j++)
            {
                if (nums1[i] == nums2[j])
                    A[i, j] = Math.Max(A[i, j], A[i - 1, j - 1] + 1);
                else
                    A[i, j] = Math.Max(A[i - 1, j], A[i, j - 1]);
            }
        }
        return A[nums1.Length - 1, nums2.Length - 1];
    }
}
// @lc code=end

