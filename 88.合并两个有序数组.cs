/*
 * @lc app=leetcode.cn id=88 lang=csharp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
public class Solution
{
    public void Merge(int[] nums1, int m, int[] nums2, int n)
    {
        int p1 = 0, p2 = 0;

        List<int> Ans = new List<int>();
        while (p1 < m && p2 < n)
        {
            if (nums1[p1] < nums2[p2]) Ans.Add(nums1[p1++]);
            else Ans.Add(nums2[p2++]);
        }

        while (p1 < m) Ans.Add(nums1[p1++]);
        while (p2 < n) Ans.Add(nums2[p2++]);

        for (int i = 0; i < m + n; i++)
            nums1[i] = Ans[i];
    }
}
// @lc code=end

