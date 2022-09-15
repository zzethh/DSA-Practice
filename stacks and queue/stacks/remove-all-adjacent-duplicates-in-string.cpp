class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() and st.top() == c) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }

        string str = "";
        while (!st.empty()) {
            str = st.top() + str;
            st.pop();
        }
        return str;
    }
};