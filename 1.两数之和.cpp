/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int Size = nums.size();
        for (int i = 0; i < Size - 1; i++)
        {
            for (int j = i + 1; j < Size; j++)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }

        return {};
    }
};
// @lc code=end
