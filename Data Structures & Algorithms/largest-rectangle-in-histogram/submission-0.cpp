class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Next Smaller Element (Right)
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                right[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty())
        {
            right[st.top()] = n;
            st.pop();
        }

        // Previous Smaller Element (Left)
        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                left[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty())
        {
            left[st.top()] = -1;
            st.pop();
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int width = right[i] - left[i] - 1;
            ans = max(ans, width * heights[i]);
        }

        return ans;
    }
};