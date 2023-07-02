class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push({s[i], i});
            }
            else if (s[i] == ')') {
                if (!st.empty() and st.top().first == '(') {
                    st.pop();
                }
                else st.push({s[i], i});
            }
        }
        while (!st.empty()) {
            s.erase(st.top().second, 1);
            st.pop();
        }
        return s;
    }
};