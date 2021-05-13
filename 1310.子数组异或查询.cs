using System;
/*
 * @lc app=leetcode.cn id=1310 lang=csharp
 *
 * [1310] 子数组异或查询
 */

// @lc code=start
public class Solution
{
    public int[] XorQueries(int[] arr, int[][] queries)
    {
        for (int i = 1; i < arr.Length; i++)
            arr[i] ^= arr[i - 1];

        int[] Ans = new int[queries.Length];

        for (int i = 0; i < queries.Length; i++)
        {
            if (queries[i][0] > 0)
                Ans[i] = arr[queries[i][1]] ^ arr[queries[i][0] - 1];
            else
                Ans[i] = arr[queries[i][1]];
        }
        return Ans;

        Stack<int> stack = new Stack<int>();
        Queue<int> queue = new Queue<int>();

    }
}
// @lc code=end

