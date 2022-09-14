class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        for (char c : s) {
            if (c == '(') {
                if (st.empty()) {
                    st.push(c);
                }
                else {
                    ans = ans + c;
                    st.push(c);
                }
            }
            else {
                if (!st.empty() and st.top() != '(') {
                    st.pop();
                }
                st.pop();
                if (!st.empty()) {
                    ans = ans + ')';
                }
            }
        }
        return ans;
    }
};