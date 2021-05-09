using System;
using Internal;
/*
 * @lc app=leetcode.cn id=1723 lang=csharp
 *
 * [1723] 完成所有工作的最短时间
 */

// @lc code=start
public class Solution
{
    // const int Inf = 0x3f3f3f3f;
    // int Ans = Inf;
    // bool check(int[] jobs, int val, int k)
    // {
    //     int p1 = 0, p2 = jobs.Length - 1;
    //     int tAns = 0;

    //     while (p1 <= p2)
    //     {
    //         int temp = 0;


    //         while (p1 <= p2 && temp + jobs[p2] <= val)
    //         {
    //             temp += jobs[p2]; p2--;
    //         }
    //         while (p1 <= p2 && temp + jobs[p1] <= val)
    //         {
    //             temp += jobs[p1]; p1++;
    //         }

    //         if (temp == 0) return false;
    //         k--;

    //         tAns = Math.Max(tAns, temp);
    //     }

    //     if (k >= 0)
    //     {
    //         Ans = Math.Min(tAns, Ans);
    //         return true;
    //     }

    //     return false;
    // }
    public int MinimumTimeRequired(int[] jobs, int k)
    {
        // Array.Sort(jobs);

        // int left = 0, right = Inf;
        // while (left <= right)
        // {
        //     int mid = (left + right) >> 1;

        //     if (check(jobs, mid, k))
        //         right = mid - 1;
        //     else
        //         left = mid + 1;
        // }

        // return Ans;

        int length = jobs.Length;

        int[] sum = new int[1 << length];

        sum[0] = 0;
        for (int i = 1; i < sum.Length; i++)
        {
            int temp = 1, cnt = 0;
            while (cnt < length)
            {
                if ((temp & i) != 0) sum[i] += jobs[cnt];
                temp <<= 1; cnt++;
            }
        }

        int[,] A = new int[k, sum.Length];
        for (int i = 0; i < sum.Length; i++)
            A[0, i] = sum[i];

        for (int i = 1; i < k; i++)
        {
            for (int j = 0; j < sum.Length; j++)
            {
                int tempMin = int.MaxValue;

                for (int state = j; state != 0; state = (state - 1) & j)
                    tempMin = Math.Min(tempMin, Math.Max(A[i - 1, j - state], sum[state]));

                A[i, j] = tempMin;
            }
        }

        return A[k - 1, sum.Length - 1];
    }
}
// @lc code=end
/*
[1867731,2710043,4771762,5011359,7567506]
2

-->11650852
*/

