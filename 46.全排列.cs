/*
 * @lc app=leetcode.cn id=46 lang=csharp
 *
 * [46] 全排列
 */

// @lc code=start
public class Solution
{
    int length;
    int[] vis = new int[15];
    IList<IList<int>> Ans = new List<IList<int>>();
    IList<int> temp = new List<int>();
    void dfs(int[] nums, int n)
    {
        if (n == length + 1)
        {
            Ans.Add(temp);
            return;
        }
        else
        {
            for (int i = 1; i <= length; i++)
            {
                if (vis[i] == 0)
                {
                    vis[i] = 1;
                    temp.Add(nums[i]);
                    dfs(nums, n + 1);
                    vis[i] = 0;
                    temp.Remove(nums[i]);
                }
            }
        }
    }
    public IList<IList<int>> Permute(int[] nums)
    {
        length = nums.Length;

        dfs(nums, 1);

        return Ans;
    }
}
// @lc code=end

