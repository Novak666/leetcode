/*
Time complexity: O(n)O(n).
Single iteration of O(n)O(n) in which each bar can be touched at most twice
(due to insertion and deletion from stack)
and insertion and deletion from stack takes O(1)O(1) time.
Space complexity: O(n)O(n).
Stack can take upto O(n)O(n) space in case of stairs-like or flat structure
*/

class Solution{
public:
    int trap(vector<int>& height){
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}
};

