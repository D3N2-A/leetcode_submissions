/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution
{
public:
   vector<int> nextSmallerElement(vector<int> &arr, int n)
    {

        stack<int> comp;
        comp.push(-1);
        vector <int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];

            while (comp.top() != -1 && arr[comp.top()] >= curr)
            {
                comp.pop();
            }
            ans[i] = comp.top();
            comp.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> &arr, int n)
    {

        stack<int> comp;
        comp.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];

            while (comp.top() != -1 && arr[comp.top()] >= curr)
            {
                comp.pop();
            }
            ans[i] = comp.top();
            comp.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int> &heights)
    {
        int ans = INT_MIN;
        int n = heights.size();
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        for (int i = 0; i < n; i++)
        {

            int h = heights[i];

            if(next[i]== -1){
                next[i]=n;
            }
            int breadth = next[i] - prev[i] - 1;
            int area = h * breadth;
            ans = max(area, ans);
       }
        return ans;
    }
};
{
public:
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {

        stack<int> comp;
        comp.push(-1);
        vector <int> ans(n);

        for (int i = n - 1; i <= 0; i++)
        {
            int curr = arr[i];

            while (comp.top() != -1 && arr[comp.top()] >= curr)
            {
                comp.pop();
            }
            ans[i] = comp.top();
            comp.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int ans = 0;
        int n = heights.size();
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        for (int i = 0; i < n; i++)
        {

            int h = heights[i];
            int breadth = next[i] - prev[i] - 1;

            int area = h * breadth;
            ans = max(area, ans);
        }
    }
};
// @lc code=end
