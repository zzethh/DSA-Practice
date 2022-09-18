class Solution {
public:
    string smallestNumber(string pattern) {
        stack<string> st;
        int num = 1;
        string str = "";
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            if (c == 'D') {
                st.push(to_string(num));
                num++;
            }
            else {
                st.push(to_string(num));
                num++;
                while (st.size() > 0) {
                    str = str + st.top();
                    st.pop();
                }
            }
        }
        st.push(to_string(num));
        while (st.size() > 0) {
            str = str + st.top();
            st.pop();
        }
        return str;
    }
};