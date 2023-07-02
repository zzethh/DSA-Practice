class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        for (auto x : s) {
            if (x == ')') {
                if (!st.empty() and st.top() == '(') {
                    st.pop();
                    continue;
                }
            }
            st.push(x);
        }
        return st.size();
    }
};