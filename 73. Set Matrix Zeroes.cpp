class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    st.insert({i, j});
                }
            }
        }
        for (auto it : st)
        {
            int i = it.first;
            int j = it.second;
            for (int k = 0; k < n; k++)
            {
                matrix[k][j] = 0;
            }
            for (int k = 0; k < m; k++)
            {
                matrix[i][k] = 0;
            }
        }
        return;
    }
};