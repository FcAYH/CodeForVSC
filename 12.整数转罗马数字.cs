/*
 * @lc app=leetcode.cn id=12 lang=csharp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
public class Solution
{
    Dictionary<int, string> dictionary = new Dictionary<int, string>();

    private void Init_()
    {
        dictionary.Add(0, "");
        dictionary.Add(1, "I");
        dictionary.Add(2, "II");
        dictionary.Add(3, "III");
        dictionary.Add(4, "IV");
        dictionary.Add(5, "V");
        dictionary.Add(6, "VI");
        dictionary.Add(7, "VII");
        dictionary.Add(8, "VIII");
        dictionary.Add(9, "IX");
        dictionary.Add(10, "X");
        dictionary.Add(20, "XX");
        dictionary.Add(30, "XXX");
        dictionary.Add(40, "XL");
        dictionary.Add(50, "L");
        dictionary.Add(60, "LX");
        dictionary.Add(70, "LXX");
        dictionary.Add(80, "LXXX");
        dictionary.Add(90, "XC");
        dictionary.Add(100, "C");
        dictionary.Add(200, "CC");
        dictionary.Add(300, "CCC");
        dictionary.Add(400, "CD");
        dictionary.Add(500, "D");
        dictionary.Add(600, "DC");
        dictionary.Add(700, "DCC");
        dictionary.Add(800, "DCCC");
        dictionary.Add(900, "CM");
        dictionary.Add(1000, "M");
        dictionary.Add(2000, "MM");
        dictionary.Add(3000, "MMM");
    }
    public string IntToRoman(int num)
    {
        Init_();
        string Ans = "";
        int bt = 1000;
        if (num / bt != 0)
        {
            Ans += dictionary[num / bt * 1000];
            num %= bt;
        }
        bt /= 10;
        if (num / bt != 0)
        {
            Ans += dictionary[num / bt * 100];
            num %= bt;
        }
        bt /= 10;
        if (num / bt != 0)
        {
            Ans += dictionary[num / bt * 10];
            num %= bt;
        }
        bt /= 10;
        if (num / bt != 0)
        {
            Ans += dictionary[num / bt];
        }
        return Ans;
    }
}
// @lc code=end

