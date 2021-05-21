/*
 * @lc app=leetcode.cn id=692 lang=csharp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
public class Solution
{
    public IList<string> TopKFrequent(string[] words, int k)
    {
        IList<string> Ans = new List<string>();
        Dictionary<string, int> dict = new Dictionary<string, int>();

        foreach (string s in words)
        {
            int value;
            if (dict.TryGetValue(s, out value))
                dict[s]++;
            else
                dict.Add(s, 1);
        }

        dict = dict.OrderBy(o => o.Key).OrderByDescending(o => o.Value).ToDictionary(o => o.Key, p => p.Value);


        foreach (KeyValuePair<string, int> i in dict)
        {
            Ans.Add(i.Key);
            k--;
            if (k == 0) break;
            // Console.WriteLine("{0} + {1}", i.Key, i.Value);
        }

        return Ans;
    }
}
// @lc code=end

