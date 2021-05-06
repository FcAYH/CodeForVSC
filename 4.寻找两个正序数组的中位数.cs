/*
 * @lc app=leetcode.cn id=4 lang=csharp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
public class Solution
{
    const int Inf = 0x3f3f3f3f;
    const int board = 1000001;
    public double FindMedianSortedArrays(int[] nums1, int[] nums2)
    {
        int length1 = nums1.Length, length2 = nums2.Length;
        int sum = length1 + length2;
        double l = -board, r = board;
        int upper = 0, lower = 0;

        while (l <= r)
        {
            double mid = (l + r) / 2.0;
            int ans = Inf;
            int left = 0, right = length1 - 1;
            while (left <= right)
            {
                int mid2 = (left + right) >> 1;

                if ((double)nums1[mid2] < mid)
                {
                    ans = mid2;
                    left = mid2 + 1;
                }
                else right = mid2 - 1;
            }
            lower += (ans == Inf) ? 0 : ans + 1;
            ans = Inf;
            left = 0; right = length2 - 1;
            while (left <= right)
            {
                int mid2 = (left + right) >> 1;

                if ((double)nums2[mid2] < mid)
                {
                    ans = mid2;
                    left = mid2 + 1;
                }
                else right = mid2 - 1;
            }
            lower += (ans == Inf) ? 0 : ans + 1;

            left = 0; right = length1 - 1;
            while (left <= right)
            {
                int mid2 = (left + right) >> 1;

                if ((double)nums1[mid2] > mid)
                {
                    ans = mid2;
                    right = mid2 - 1;
                }
                else left = mid2 - 1;
            }
            upper += (ans == Inf) ? 0 : ans + 1;
            ans = Inf;
            left = 0; right = length2 - 1;
            while (left <= right)
            {
                int mid2 = (left + right) >> 1;

                if ((double)nums2[mid2] > mid)
                {
                    ans = mid2;
                    right = mid2 - 1;
                }
                else left = mid2 + 1;
            }
            upper += (ans == Inf) ? 0 : ans + 1;

            if (sum % 2 == 0)
            {
                if (lower <= sum / 2 && upper >= sum / 2 + 1) return mid;
            }
            else if (lower <= sum / 2 && upper >= sum / 2 + 2) return mid;

            if (upper <= sum / 2) l = mid + 1;
            if (lower > sum / 2) r = mid - 1;
        }

        return 404;
    }
}
// @lc code=end

//[]\n[2,3]
//[2,2,4,4]\n[2,2,4,4]
//[1,2]\n[3,4]
