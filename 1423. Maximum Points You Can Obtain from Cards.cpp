class Solution
{
public:
    int maxScore(vector<int> &arr, int k)
    {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += arr[i];
        }
        int ans = sum;
        int r = n - 1;
        for (int i = k - 1; i >= 0; i--)
        {
            sum -= arr[i];
            sum += arr[r];
            ans = max(ans, sum);
            r--;
        }
        return ans;
    }
};