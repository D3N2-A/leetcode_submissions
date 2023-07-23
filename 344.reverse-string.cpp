/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        stack<char> str;
        for (int i = 0; i < s.size(); i++)
        {
            str.push(s[i]);
        }
        s.clear();
        while (!str.empty())
        {
            char ch = str.top();
            s.push_back(ch);
            str.pop();
        }
        return;
    }
};
// @lc code=end
