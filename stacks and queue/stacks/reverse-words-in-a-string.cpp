class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stack<string> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;
            int j = i;
            while (s[j] != ' ' and s[j] != '\0') {
                j++;
            }
            st.push(s.substr(i, j - i));
            i = j;
        }
        while (!st.empty()) {
            if (st.size() == 1) ans = ans + st.top();
            else ans = ans + st.top() + " ";
            st.pop();
        }
        return ans;
    }
};