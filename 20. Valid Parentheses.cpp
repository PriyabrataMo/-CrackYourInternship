class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto it : s)
        {
            if (st.empty())
            {
                if (it == ')' || it == '}' || it == ']')
                    return false;
                else
                    st.push(it);
            }
            else if (it == ')' && st.top() == '(')
            {
                st.pop();
            }
            else if (it == '}' && st.top() == '{')
            {
                st.pop();
            }
            else if (it == ']' && st.top() == '[')
            {
                st.pop();
            }
            else
                st.push(it);
        }

        return st.empty();
    }
};