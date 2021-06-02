/*
 * @lc app=leetcode.cn id=621 lang=csharp
 *
 * [621] 任务调度器
 */

// @lc code=start
public class Solution
{
    public int LeastInterval(char[] tasks, int n)
    {
        int length = tasks.Length;
        int[] cnt = new int[26];

        for (int i = 0; i < length; i++)
        {
            cnt[tasks[i] - 'A']++;
        }

        int maxTaskCnt = 0, maxTasks = 0;

        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > maxTaskCnt)
            {
                maxTaskCnt = cnt[i];
                maxTasks = 1;
            }
            else if (cnt[i] == maxTaskCnt)
                maxTasks++;
        }

        int a = length - maxTaskCnt - maxTasks + 1;
        int b = n * (maxTaskCnt - 1);
        if (a < b)
            return (n + 1) * (maxTaskCnt - 1) + maxTasks;
        else
            return length;
    }
}
// @lc code=end

