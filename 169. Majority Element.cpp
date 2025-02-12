class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                num = nums[i];
                count++;
            }
            else if (num == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return num;
    }
};