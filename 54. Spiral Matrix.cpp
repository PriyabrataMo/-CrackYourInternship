class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int r = m - 1;
        int t = 0;
        int b = n - 1;
        vector<int> ans;
        while (l <= r && t <= b)
        {
            cout << l << r << endl;
            cout << t << b << endl;

            int left = l;
            while (left <= r)
            {
                ans.push_back(mat[t][left]);
                left++;
            }
            t++;

            int top = t;
            while (top <= b)
            {
                ans.push_back(mat[top][r]);
                top++;
            }
            r--;
            if (t <= b)
            {
                int right = r;
                while (l <= right)
                {
                    ans.push_back(mat[b][right]);
                    right--;
                }
                b--;
            }
            if (l <= r)
            {
                int bottom = b;
                while (t <= bottom)
                {
                    ans.push_back(mat[bottom][l]);
                    bottom--;
                }
                l++;
            }
        }
        return ans;
    }
};