/*
 * @lc app=leetcode.cn id=36 lang=csharp
 *
 * [36] 有效的数独
 */

// @lc code=start
public class Solution
{
    const int NumberCounter = 10;
    public bool IsValidSudoku(char[][] board)
    {
        int[,] visRow = new int[board.Length, NumberCounter];
        int[,] visCol = new int[board.Length, NumberCounter];
        int[,] visBlock = new int[board.Length, NumberCounter];

        bool valid = true;
        for (int i = 0; i < board.Length; i++)
        {
            for (int j = 0; j < board.Length; j++)
            {
                if (board[i][j] == '.') continue;

                if (visRow[i, board[i][j] - '1'] == 0)
                {
                    visRow[i, board[i][j] - '1'] = 1;
                }
                else valid = false;

                if (visCol[j, board[i][j] - '1'] == 0)
                {
                    visCol[j, board[i][j] - '1'] = 1;
                }
                else valid = false;

                if (visBlock[i / 3 * 3 + j / 3, board[i][j] - '1'] == 0)
                {
                    visBlock[i / 3 * 3 + j / 3, board[i][j] - '1'] = 1;
                }
                else valid = false;

                if (valid == false)
                    break;
            }

            if (valid == false)
                break;
        }

        return valid;
    }
}
// @lc code=end

