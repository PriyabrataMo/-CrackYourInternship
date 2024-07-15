class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = (nums[i] + pre[i - 1]);
        }
        map<int, int> mpp;
        mpp[0]++;
        int ans = 0;
        for (auto it : pre)
        {
            int m = it % k;
            if (m < 0)
                m += k;
            if (mpp[m] != 0)
            {
                ans += mpp[m];
            }
            mpp[m]++;
        }
        return ans;
    }
};