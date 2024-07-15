class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int f = nums[0];
        int s = nums[0];
        f = nums[nums[f]];
        s = nums[s];

        while (f != s)
        {
            s = nums[s];
            f = nums[nums[f]];
        }
        s = nums[0];

        while (f != s)
        {
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};