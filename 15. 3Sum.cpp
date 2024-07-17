class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (long long int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            long long int j, k;
            j = i + 1;
            k = n - 1;
            while (j < k)
            {
                long long int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    vector<int> s;
                    s.push_back(nums[i]);
                    s.push_back(nums[j]);
                    s.push_back(nums[k]);
                    ans.push_back(s);
                    j++;
                    k--;
                    while ((j < k) && (nums[j] == nums[j - 1]))
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
            }
        }

        return ans;
    }
};