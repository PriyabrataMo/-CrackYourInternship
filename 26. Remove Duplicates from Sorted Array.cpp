class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int ind = 1;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[ind] = nums[i];

                ind++;
            }
        }
        return ind;
    }
};