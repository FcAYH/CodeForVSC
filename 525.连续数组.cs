/*
 * @lc app=leetcode.cn id=525 lang=csharp
 *
 * [525] 连续数组
 */

// @lc code=start
public class Solution 
{
    public int FindMaxLength(int[] nums) 
    {
        int[] prefix = new int[nums.Length + 1];
        for (int i = 1; i < nums.Length; i++)
            prefix[i] = prefix[i - 1] + ((nums[i - 1] == 0) ? -1 : 1);

        int Ans = 0;
        Dictionary<int, int> set = new Dictionary<int, int>();
        for (int i = 1; i <= nums.Length; i++)
        {
            if (set.ContainsKey(prefix[i]))
                Ans = Math.Max(Ans, i - set[prefix[i]]);
            else 
                set.Add(prefix[i], i);
        }

        return Ans;
    }
}
// @lc code=end

