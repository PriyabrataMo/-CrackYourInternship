class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int t)
    {
        int n = nums.size();
        if (n <= 3)
            return {};
        map<long long, long long> mpp;
        for (auto it : nums)
        {
            mpp[it]++;
        }
        set<vector<int>> a;

        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]--;
            for (int j = i + 1; j < n; j++)
            {
                mpp[nums[j]]--;
                for (int k = j + 1; k < n; k++)
                {
                    mpp[nums[k]]--;
                    long long req = 1LL * t - 1LL * nums[i] - 1LL * nums[j] - 1LL * nums[k];
                    if (mpp.find(req) != mpp.end() && mpp[req] > 0)
                    {
                        vector<int> ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[k]);
                        ans.push_back(int(req));
                        sort(ans.begin(), ans.end());
                        a.insert(ans);
                    }
                    mpp[nums[k]]++;
                }
                mpp[nums[j]]++;
            }
            mpp[nums[i]]++;
        }

        vector<vector<int>> temp(a.begin(), a.end());
        return temp;
    }
};