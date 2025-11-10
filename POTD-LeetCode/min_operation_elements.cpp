class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ops = 0;
        for (int x : nums) {
            if (x == 0) {
                while (!st.empty() && st.top() > 0) st.pop();
                continue;
            }
        
            while (!st.empty() && st.top() > x) st.pop();
            if (!st.empty() && st.top() == x) continue;
            st.push(x);
            ++ops;
        }
        return ops;
    }
};