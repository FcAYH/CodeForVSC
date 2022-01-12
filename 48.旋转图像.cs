/*
 * @lc app=leetcode.cn id=48 lang=csharp
 *
 * [48] 旋转图像
 */

// @lc code=start
public class Solution
{
    public void Rotate(int[][] matrix)
    {
        int range = (int)Math.Ceiling((double)matrix.Length / 2.0);
        //Console.WriteLine(range);
        int n = matrix.Length;
        for (int i = 0; i < range; i++)
        {
            int pX1 = i, pY1 = i;
            int pX2 = n - i - 1, pY2 = i;
            int pX3 = n - i - 1, pY3 = n - i - 1;
            int pX4 = i, pY4 = n - i - 1;
            for (int j = i; j < n - i - 1; j++)
            {
                int temp = matrix[pX1][pY1];
                matrix[pX1][pY1] = matrix[pX2][pY2];
                matrix[pX2][pY2] = matrix[pX3][pY3];
                matrix[pX3][pY3] = matrix[pX4][pY4];
                matrix[pX4][pY4] = temp;

                pY1++;
                pX2--;
                pY3--;
                pX4++;
            }
        }

        //return matrix;
    }
}
// @lc code=end

