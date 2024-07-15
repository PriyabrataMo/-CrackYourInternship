class Solution
{
public:
    int largestRectangleArea(vector<int> &a)
    {
        stack<pair<int, int>> st;
        st.push({a[0], 1});
        int ans = 0;
        int n = a.size();
        for (int i = 1; i < n; i++)
        {

            if (a[i] < st.top().first)
            {
                int c = 0;
                while (!st.empty() && a[i] < st.top().first)
                {
                    int temp = ((st.top().second) + c) * st.top().first;
                    // cout<<temp<<" "<<st.top().second<<endl;
                    ans = max(ans, ((st.top().second) + c) * st.top().first);
                    c += st.top().second;
                    st.pop();
                }
                st.push({a[i], c + 1});
            }
            else
            {
                st.push({a[i], 1});
            }
        }
        int c = 0;
        while (!st.empty())
        {
            // cout<<st.top().first<<endl;

            ans = max(ans, ((st.top().second) + c) * st.top().first);
            c += st.top().second;
            st.pop();
        }
        return ans;
    }
};