/*
 * @lc app=leetcode.cn id=6 lang=csharp
 *
 * [6] Z 字形变换
 */

// @lc code=start
public class Solution
{
    public string Convert(string s, int numRows)
    {
        char[,] temp = new char[numRows, s.Length];

        int p = 0, col = 0, row = 0, up = 0;
        while (p < s.Length)
        {
            temp[row, col] = s[p++];

            if (row == numRows - 1) up = 1;
            else if (row == 0) up = 0;

            if (up == 1)
            {
                if (row > 0)
                    row--;
                col++;
            }
            else row++;
        }

        string Ans = "";
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j <= Math.Min(col, s.Length - 1); j++)
            {
                if (temp[i, j] != '\0')
                {
                    Ans += temp[i, j];
                }
            }
        }
        return Ans;
    }
}
// @lc code=end

