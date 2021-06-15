/*
 * @lc app=leetcode.cn id=374 lang=csharp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution : GuessGame
{
    public int GuessNumber(int n)
    {
        int left = 1, right = n, Ans = 0;

        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);

            int check = guess(mid);
            if (check == 0)
            {
                Ans = mid;
                break;
            }

            if (check == 1) left = mid + 1;
            else right = mid - 1;
        }

        return Ans;
    }
}
// @lc code=end

