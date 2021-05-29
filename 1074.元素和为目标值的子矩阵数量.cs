using System;
/*
 * @lc app=leetcode.cn id=1074 lang=csharp
 *
 * [1074] 元素和为目标值的子矩阵数量
 */

// @lc code=start
public class Solution
{
    public int NumSubmatrixSumTarget(int[][] matrix, int target)
    {
        int row = matrix.Length, col = matrix[0].Length;
        int[,] temp = new int[matrix.Length + 1, matrix[0].Length + 1];

        for (int i = 0; i < matrix.Length; i++)
            for (int j = 0; j < matrix[0].Length; j++)
                temp[i + 1, j + 1] = matrix[i][j];

        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++)
                temp[i, j] += temp[i - 1, j] + temp[i, j - 1] - temp[i - 1, j - 1];

        int Ans = 0;

        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++)
                for (int k = i; k <= row; k++)
                    for (int l = j; l <= col; l++)
                        if (temp[k, l] - temp[i - 1, l] - temp[k, j - 1] + temp[i - 1, j - 1] == target)
                            Ans++;

        return Ans;
    }
}
// @lc code=end

