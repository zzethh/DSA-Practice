class Solution {
public:
    string reverseParentheses(string s) {
        stack<pair<int, int>> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                while (!st.empty() and st.top().first != '(') {
                    st.pop();
                }
                reverse(s.begin() + st.top().second, s.begin() + i);
                st.pop();
            }
            st.push({s[i], i});
        }
        string t = "";
        for (auto x : s) {
            if (x != '(' and x != ')') {
                t += x;
            }
        }
        return t;
    }
};