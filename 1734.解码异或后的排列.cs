/*
 * @lc app=leetcode.cn id=1734 lang=csharp
 *
 * [1734] 解码异或后的排列
 */

// @lc code=start
public class Solution
{
    public int[] Decode(int[] encoded)
    {
        int[] decode = new int[encoded.Length + 1];

        decode[0] = 0;
        for (int i = 1; i < encoded.Length; i += 2)
            decode[0] ^= encoded[i];

        for (int i = 1; i <= encoded.Length + 1; i++)
            decode[0] ^= i;

        for (int i = 1; i <= encoded.Length; i++)
            decode[i] = decode[i - 1] ^ encoded[i - 1];

        return decode;
    }
}
// @lc code=end

