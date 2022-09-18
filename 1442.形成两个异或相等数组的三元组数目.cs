/*
 * @lc app=leetcode.cn id=1442 lang=csharp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */

// @lc code=start
public class Solution
{
    public int CountTriplets(int[] arr)
    {
        int length = arr.Length;
        for (int i = 1; i < length; i++)
            arr[i] ^= arr[i - 1];

        int Ans = 0;

        {
            int i = 0;
            for (int k = i + 1; k < length; k++)
                for (int j = i + 1; j <= k; j++)
                    if (arr[j - 1] == (arr[k] ^ arr[j - 1]))
                        Ans++;
        }

        for (int i = 1; i < length - 1; i++)
            for (int k = i + 1; k < length; k++)
                for (int j = i + 1; j <= k; j++)
                    if ((arr[j - 1] ^ arr[i - 1]) == (arr[k] ^ arr[j - 1]))
                        Ans++;

        return Ans;
    }
}
// @lc code=end

