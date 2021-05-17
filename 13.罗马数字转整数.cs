/*
 * @lc app=leetcode.cn id=13 lang=csharp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
public class Solution
{
    Dictionary<char, int> dictionary = new Dictionary<char, int>();
    private void Init_()
    {
        dictionary.Add('I', 1);
        dictionary.Add('V', 5);
        dictionary.Add('X', 10);
        dictionary.Add('L', 50);
        dictionary.Add('C', 100);
        dictionary.Add('D', 500);
        dictionary.Add('M', 1000);
    }
    public int RomanToInt(string s)
    {
        Init_();

        int Ans = 0;
        foreach (char ch in s)
            Ans += dictionary[ch];

        for (int i = 0; i < s.Length - 1; i++)
        {
            if ((s[i] == 'I' && s[i + 1] == 'V') || (s[i] == 'I' && s[i + 1] == 'X'))
                Ans -= 2;

            if ((s[i] == 'X' && s[i + 1] == 'L') || (s[i] == 'X' && s[i + 1] == 'C'))
                Ans -= 20;

            if ((s[i] == 'C' && s[i + 1] == 'D') || (s[i] == 'C' && s[i + 1] == 'M'))
                Ans -= 200;
        }

        return Ans;
    }
}
// @lc code=end

