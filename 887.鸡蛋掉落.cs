using System;
using System.Runtime.Serialization;
using System.Xml.Xsl.Runtime;
/*
 * @lc app=leetcode.cn id=887 lang=csharp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
public class Solution
{
    const int Inf = 0x3f3f3f3f;
    public int SuperEggDrop(int k, int n)
    {
        int[,] A = new int[k + 1, n + 1];
        for (int i = 1; i <= n; i++) A[1, i] = i;
        for (int i = 1; i <= k; i++) A[i, 1] = 1;

        for (int i = 2; i <= k; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                A[i, j] = Inf;

                int left = 1, right = j;

                int upper = right;
                while (left <= right)
                {
                    int mid = (left + right) >> 1;

                    if (A[i - 1, mid - 1] >= A[i, j - mid])
                    {
                        upper = mid;
                        right = mid - 1;
                    }
                    else left = mid + 1;
                }

                left--;
                Console.WriteLine(left.ToString() + " " + upper.ToString());
                Console.WriteLine(i.ToString() + " " + j.ToString());
                //return 1;
                A[i, j] = Math.Min
                (
                    Math.Max(A[i, left - 1], A[i - 1, j - left]) + 1,
                    Math.Max(A[i, upper - 1], A[i - 1, j - upper]) + 1
                );

                // for (int temp = 1; temp <= j; temp++)
                //     A[i, j] = Math.Min(A[i, j], Math.Max(A[i, j - temp], A[i - 1, temp - 1]) + 1);
            }
        }

        return A[k, n];
    }
}
// @lc code=end

/*
2\n6
3\n14
*/
