class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int d = 0;
        int maxi = 0;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
                d++;
                maxi = max(maxi, d);
            }
            else if (c == ')') {
                while (!st.empty() and st.top() != '(') {
                    st.pop();
                }
                st.pop();
                d--;
            }
        }
        return maxi;
    }
};