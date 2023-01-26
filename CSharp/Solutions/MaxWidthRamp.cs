namespace Solutions;

public class MaxWidthRamp
{
    private struct Number : IComparable
    {
        public int Value;
        public int Index;

        public int CompareTo(object? obj)
        {
            if (Value > ((Number)obj).Value)
                return 1;
            else if (Value == ((Number)obj).Value)
            {
                if (Index > ((Number)obj).Index)
                    return 1;
                else return -1;
            }
            else
                return -1;
        }
    }

    private Number[] _nums;

    public int Solve(int[] nums)
    {
        int length = nums.Length;
        _nums = new Number[length];

        for (int i = 0; i < length; i++)
        {
            _nums[i].Value = nums[i];
            _nums[i].Index = i;
        }

        Array.Sort(_nums);

        int minIndex = length;
        int ans = 0;
        for (int i = 0; i < length; i++)
        {
            ans = Math.Max(ans, _nums[i].Index - minIndex);
            minIndex = Math.Min(minIndex, _nums[i].Index);
        }

        return ans;
    }
}
