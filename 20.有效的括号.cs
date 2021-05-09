/*
 * @lc app=leetcode.cn id=20 lang=csharp
 *
 * [20] 有效的括号
 */

// @lc code=start
public class Solution
{
    public bool IsValid(string s)
    {
        if (s.Length % 2 == 1)
            return false;

        Stack<char> stack = new Stack<char>();

        foreach (char ch in s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
                stack.Push(ch);

            else if (stack.Count == 0)
                return false;

            else if (ch == ')' && stack.Peek() == '(')
                stack.Pop();

            else if (ch == ']' && stack.Peek() == '[')
                stack.Pop();

            else if (ch == '}' && stack.Peek() == '{')
                stack.Pop();

            else return false;
        }

        return (stack.Count == 0) ? true : false;
    }
}
// @lc code=end

