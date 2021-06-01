/*
 * @lc app=leetcode.cn id=1744 lang=csharp
 *
 * [1744] 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 */

// @lc code=start
public class Solution
{
    public bool[] CanEat(int[] candiesCount, int[][] queries)
    {
        int Length = candiesCount.Length;

        long[] prefix = new long[Length];
        prefix[0] = candiesCount[0];
        for (int i = 1; i < Length; ++i)
        {
            prefix[i] = prefix[i - 1] + candiesCount[i];
        }

        int qLength = queries.Length;
        bool[] Ans = new bool[qLength];

        for (int i = 0; i < qLength; ++i)
        {
            int[] query = queries[i];
            int favoriteType = query[0], favoriteDay = query[1], dailyCap = query[2];

            long val1 = favoriteDay + 1;
            long val2 = (long)(favoriteDay + 1) * dailyCap;
            long val3 = favoriteType == 0 ? 1 : prefix[favoriteType - 1] + 1;
            long val4 = prefix[favoriteType];

            Ans[i] = !(val1 > val4 || val2 < val3);
        }
        return Ans;
    }
}

// @lc code=end

/*
[16,38,8,41,30,31,14,45,3,2,24,23,38,30,31,17,35,4,9,42,28,18,37,18,14,46,11,13,19,3,5,39,24,48,20,29,4,19,36,11,28,49,38,16,23,24,4,22,29,35,45,38,37,40,2,37,8,41,33,8,40,27,13,4,33,5,8,14,19,35,31,8,8]
[[43,1054,49]]
*/
