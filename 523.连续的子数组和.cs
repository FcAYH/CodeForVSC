using System.Xml.Xsl.Runtime;
/*
 * @lc app=leetcode.cn id=523 lang=csharp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
public class Solution
{
    public bool CheckSubarraySum(int[] nums, int k)
    {
        int[] prefix = new int[nums.Length];

        prefix[0] = nums[0] % k;
        for (int i = 1; i < nums.Length; i++)
            prefix[i] = (prefix[i - 1] + nums[i]) % k;

        Dictionary<int, int> set = new Dictionary<int, int>();
        set.Add(0, -1);

        for (int i = 0; i < nums.Length; i++)
        {
            if (set.ContainsKey(prefix[i]))
            {
                //Console.Write("{0} {1} {2}", i, prefix[i], set.IndexOfKey(prefix[i]));
                if (i - set[prefix[i]] > 1)
                    return true;
            }
            else
                set.Add(prefix[i], i);
        }

        return false;
    }
}
// @lc code=end

/*
[2,2,1,3,4]\n5

[23,2,4,6,6]\n7

2,4,1,0,2

[0]\n1

[5,0,0,0]\n3

[2,4,3]
6
*/
