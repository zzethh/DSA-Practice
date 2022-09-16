class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            if (!st.empty() and ((st.top() == s[i] + 32) or (st.top() == s[i] - 32))) {
                st.pop();
            }
            else st.push(s[i]);
        }

        while (!st.empty()) {
            str = st.top() + str;
            st.pop();
        }
        return str;
    }
};