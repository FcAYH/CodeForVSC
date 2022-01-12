/*
 * @lc app=leetcode.cn id=151 lang=csharp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
public class Solution
{
    public string ReverseWords(string s)
    {
        string[] words = s.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        string newSentence = "";

        for (int i = words.Length - 1; i >= 0; i--)
        {
            newSentence += words[i];
            if (i != 0)
                newSentence += " ";
        }

        return newSentence;
    }
}
// @lc code=end

