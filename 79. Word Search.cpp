class Solution
{
public:
    int n;
    int m;
    int arr[4] = {-1, 0, 1, 0};
    bool valid(int r, int c)
    {
        return r >= 0 && c >= 0 && r < n && c < m;
    }
    bool func(int r, int c, vector<vector<char>> &board, vector<vector<int>> &vis, string &word, int ind)
    {
        if (ind == (word.size()) - 1)
        {
            if (board[r][c] != word[ind])
                return false;
            else
                return true;
        }
        if (board[r][c] != word[ind])
            return false;

        // cout<<r<<" "<<c<<" "<<ind<<endl;

        bool ans = false;
        for (int i = 0; i <= 3; i++)
        {
            int nr = r + arr[i];
            int nc = c + arr[3 - i];

            if (valid(nr, nc) && vis[nr][nc] == 0 && board[nr][nc] == word[ind + 1])
            {
                // cout<<board[nr][nc]<<endl;
                vis[nr][nc] = 1;
                ans = ans | func(nr, nc, board, vis, word, ind + 1);
                vis[nr][nc] = 0;
            }
        }
        vis[r][c] = 0;

        return ans;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size();
        m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // cout<<i<<" "<<j<<endl;
                vis[i][j] = 1;
                if (func(i, j, board, vis, word, 0))
                {

                    return true;
                }
                vis[i][j] = 0;
            }
        }
        return false;
    }
};