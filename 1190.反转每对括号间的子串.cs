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
        char[] temp = new char[s.Length];
        temp = s.ToCharArray();

        int[] pos = new int[s.Length];

        for (int i = 0; i < s.Length; i++)
        {
            if (temp[i] == '(')
                pos[i] = i;
            else
                pos[i] = (i == 0) ? 0 : pos[i - 1];

            if (i != 0 && temp[i - 1] == ')')
                pos[i] = (pos[i - 1] - 1 == 0) ? 0 : pos[pos[i - 1] - 1];
        }

        for (int i = 0; i < s.Length; i++)
            Console.Write("{0} ", pos[i]);

        string S = "";
        return S;
    }
}
// @lc code=end

/*
a ( u ( l o v e ) i ) b  (  c  s  s  (  g  h  )  ) s"
0 1 1 3 3 3 3 3 3 1 1 0 12 12 12 12 16 16 16 16 12 0 
*/
