class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int ind = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (ind == n - 1)
                return 1;
            if (nums[i] == 0 && i == ind)
            {
                return 0;
            }
            ind = max(ind, i + nums[i]);
        }
        return 1;
    }
};