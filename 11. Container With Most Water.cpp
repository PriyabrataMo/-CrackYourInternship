class Solution
{
public:
    int maxArea(vector<int> &nums)
    {
        int ans = 0;
        int l = 0;
        int r = nums.size() - 1;

        while (l < r)
        {
            ans = max(ans, (min(nums[r], nums[l]) * (r - l)));
            if (nums[r] > nums[l])
            {
                l++;
            }
            else
                r--;
        }
        return ans;
    }
};