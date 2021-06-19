using System;
/*
 * @lc app=leetcode.cn id=1239 lang=csharp
 *
 * [1239] 串联字符串的最大长度
 */

// @lc code=start
public class Solution
{
    private int length;
    private int CheckAndCalc(int x, IList<string> arr)
    {
        int[] vis = new int[26];
        Array.Fill(vis, 0);

        int retVal = 0;
        for (int i = 0; i < length; i++)
        {
            if (((1 << i) & x) != 0)
            {
                for (int j = 0; j < arr[i].Length; j++)
                {
                    if (vis[arr[i][j] - 'a'] == 0)
                    {
                        vis[arr[i][j] - 'a'] = 1;
                        retVal++;
                    }
                    else return 0;
                }
            }
        }

        return retVal;
    }
    public int MaxLength(IList<string> arr)
    {
        length = arr.Count;
        int Ans = 0;

        for (int i = 1; i < (1 << length); i++)
            Ans = Math.Max(Ans, CheckAndCalc(i, arr));

        return Ans;
    }
}
// @lc code=end

