/*
 * @lc app=leetcode.cn id=1190 lang=csharp
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
public class Solution
{
    public string ReverseParentheses(string s)
    {
        char[] temp = new char[s.Length](s.ToCharArray());
        for (int i = 0; i < s.Length; i++)
        {
            if (temp[i] == '(')
            {
                int tp = i;
                Stack<char> S = new Stack<char>();
                while (temp[tp] != ')')
                    S.Add(temp[tp++]);

                tp = i;
                while (S.Count != 0)
                {
                    temp[tp] = S.Pop();
                    if (temp[tp] == '(') temp[tp] = ')';
                    else if (temp[tp] == ')') temp[tp] = '(';
                }
            }
        }
    }
}
// @lc code=end

