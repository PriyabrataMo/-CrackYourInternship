class Solution
{
public:
    int n, m;
    bool val(int x, int y)
    {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        n = board.size();
        m = board[0].size();
        int arr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int brr[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int c = 0;
                // cout<<i<<" "<<j<<" "<<endl;;
                for (int k = 0; k <= 7; k++)
                {
                    int nr = i + arr[k];
                    int nc = j + brr[k];
                    if ((val(nr, nc)) && (board[nr][nc] == 1 || board[nr][nc] == 3))
                    {
                        c++;
                        // cout<<k<<endl;
                        // cout<<nr<<" "<<nc<<" ";
                    }
                }

                // cout<<c<<endl;
                if (board[i][j] == 0)
                {
                    if (c == 3)
                    {
                        board[i][j] = 2;
                    }
                }
                else
                {
                    if (c < 2)
                    {
                        board[i][j] = 3;
                    }
                    if (c > 3)
                    {
                        board[i][j] = 3;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 2)
                {
                    board[i][j] = 1;
                }
                if (board[i][j] == 3)
                {
                    board[i][j] = 0;
                }
            }
        }
    }
};