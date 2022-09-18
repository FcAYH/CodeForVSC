/*
 * @lc app=leetcode.cn id=1849 lang=csharp
 *
 * [1849] 将字符串拆分为递减的连续值
 */

// @lc code=start
public class Solution
{
    int length = 0, flag = 0;
    int[] temp;
    private void dfs(int k, int remain, string s)
    {
        if (flag == 1) return;

        if (k == 1)
        {
            temp[k] = remain;
            if (check(temp.Length - 1, s) == true)
                flag = 1;
            return;
        }

        for (int i = 1; i <= remain - k + 1; i++)
        {
            temp[k] = i;
            dfs(k - 1, remain - i, s);
        }
    }
    private bool check(int k, string s)
    {
        long[] number = new long[k + 1];

        int p = 0;
        for (int i = 1; i <= k; i++)
        {
            number[i] = 0;

            for (int j = p; j < p + temp[i]; j++)
                number[i] = number[i] * 10 + s[j] - '0';

            p += temp[i];
        }

        for (int i = 2; i <= k; i++)
            if (number[i] != number[i - 1] - 1)
                return false;

        return true;
    }
    public bool SplitString(string s)
    {
        length = s.Length;

        for (int i = 2; i <= length; i++)
        {
            temp = new int[i + 1];
            dfs(i, length, s);

            if (flag == 1) return true;
        }

        return false;
    }
}
// @lc code=end

