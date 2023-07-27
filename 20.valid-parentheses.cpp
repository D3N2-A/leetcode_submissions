/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        int length = s.size();
        stack<char> st;

        if (length == 1)
        {
            return false;
        }
        for (int i = 0; i < length; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {

                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                else
                {

                    if (s[i] == ')' && st.top() == '(')
                    {
                        st.pop();
                    }
                    else if (s[i] == '}' && st.top() == '{')
                    {
                        st.pop();
                    }
                    else if (s[i] == ']' && st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
