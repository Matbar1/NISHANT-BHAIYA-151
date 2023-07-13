class Solution {
public:
    
int largestRectangleArea(std::vector<int>& heights) {
    int n = heights.size();
    std::stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[st.top()] > heights[i])) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = std::max(maxArea, h * width);
        }
        st.push(i);
    }

    return maxArea;
}
        
    
};