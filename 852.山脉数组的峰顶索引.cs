/*
 * @lc app=leetcode.cn id=852 lang=csharp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
public class Solution
{
    public int PeakIndexInMountainArray(int[] arr)
    {
        for (int i = 1; i < arr.Length; i++)
            if (arr[i] < arr[i - 1])
                return i - 1;

        return arr.Length - 1;
    }
}
// @lc code=end

