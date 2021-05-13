/*
 * @lc app=leetcode.cn id=1856 lang=csharp
 *
 * [1856] 子数组最小乘积的最大值
 */

// @lc code=start
public class Solution
{
    const long Mod = (long)1e9 + 7;

    public int MaxSumMinProduct(int[] nums)
    {
        int[] minNumsL = new int[nums.Length];
        int[] minNumsR = new int[nums.Length];

        Stack<int> stack = new Stack<int>();
        Stack<int> pos = new Stack<int>();
        stack.Push(nums[0]); pos.Push(0);

        minNumsL[0] = -1;

        for (int i = 1; i < nums.Length; i++)
        {
            while (stack.Count != 0 && stack.Peek() >= nums[i])
            {
                stack.Pop(); pos.Pop();
            }

            minNumsL[i] = (stack.Count == 0) ? -1 : pos.Peek();

            stack.Push(nums[i]); pos.Push(i);
        }

        stack.Clear(); pos.Clear();
        stack.Push(nums[nums.Length - 1]); pos.Push(nums.Length - 1);

        minNumsR[nums.Length - 1] = nums.Length;

        for (int i = nums.Length - 2; i >= 0; i--)
        {
            while (stack.Count != 0 && stack.Peek() >= nums[i])
            {
                stack.Pop(); pos.Pop();
            }

            minNumsR[i] = (stack.Count == 0) ? nums.Length : pos.Peek();

            stack.Push(nums[i]); pos.Push(i);
        }

        long[] temp = new long[nums.Length];
        temp[0] = nums[0];
        for (int i = 1; i < nums.Length; i++)
            temp[i] = (long)nums[i] + temp[i - 1];

        long Ans = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            if (minNumsL[i] == -1)
                Ans = Math.Max(Ans, (temp[minNumsR[i] - 1]) * (temp[i] - ((i == 0) ? 0 : temp[i - 1])));
            else
            {
                //Console.WriteLine("{0} -- {1} + {2}",minNumsL[i], minNumsR[i], i);
                Ans = Math.Max(Ans, (temp[minNumsR[i] - 1] - temp[minNumsL[i]]) * (temp[i] - temp[i - 1]));
            }
            //Console.WriteLine(Ans);
        }

        return (int)(Ans % Mod);
    }
}
// @lc code=end

