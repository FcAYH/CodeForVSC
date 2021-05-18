/*
 * @lc app=leetcode.cn id=1738 lang=csharp
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
public class Solution
{
    public int KthLargestValue(int[][] matrix, int k)
    {
        int row = matrix.Length, col = matrix[0].Length;

        for (int i = 0; i < row; i++)
        {
            for (int j = 1; j < col; j++)
                matrix[i][j] ^= matrix[i][j - 1];

            for (int j = 0; j < col; j++)
            {
                if (i != 0)
                    matrix[i][j] ^= matrix[i - 1][j];
            }

        }

        // for (int i = 0; i < row; i++)
        // {
        //     foreach (int j in matrix[i])
        //     {
        //         Console.Write("{0} ", j);
        //     }
        //     Console.Write("\n");
        // }

        List<int> allElement = new List<int>();
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                allElement.Add(matrix[i][j]);

        allElement.Sort();
        allElement.Reverse();

        // foreach (int i in allElement)
        // {
        //     Console.Write("{0} ", i);
        // }

        return allElement[k - 1];
    }
}
// @lc code=end

/*
[[10,9,5],[2,0,4],[1,0,9],[3,4,8]]\n10
*/
