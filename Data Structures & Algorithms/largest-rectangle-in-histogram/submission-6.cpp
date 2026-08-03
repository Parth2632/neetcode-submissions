class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int ans = 0;

        vector<int> right(heights.size(), heights.size());
        vector<int> left(heights.size(), -1);

        stack<int> st;

        // Find first smaller element on the right
        for(int i = 0; i < heights.size(); i++) {

            while(!st.empty() && heights[st.top()] > heights[i]) {
                right[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }


        stack<int> s;

        // Find first smaller element on the left
        for(int i = heights.size() - 1; i >= 0; i--) {

            while(!s.empty() && heights[s.top()] > heights[i]) {
                left[s.top()] = i;
                s.pop();
            }

            s.push(i);
        }


        // Calculate maximum area
        for(int i = 0; i < heights.size(); i++) {

            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;

            ans = max(ans, area);
        }

        return ans;
    }
};