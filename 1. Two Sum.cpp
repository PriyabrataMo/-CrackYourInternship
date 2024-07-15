class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mpp;
        vector<int> sol;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            int more = target - a;
            if (mpp.find(more) != mpp.end())
            {
                sol.push_back(mpp[more]);
                sol.push_back(i);
            }
            mpp[a] = i;
        }
        return sol;
    }
};