class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        // if(s.length()==3 or s.length()==1){
        //     return false;
        // }
        bool flag = false;
        for (char c : s) {
            switch (c) {
            case '(':

            case '{':

            case '[': st.push(c);
                break;

            case ']': if (!st.empty() and st.top() == '[') {
                    st.pop();
                    break;
                } else {
                    return false;
                }

            case '}': if (!st.empty() and st.top() == '{') {
                    st.pop();
                    break;
                } else {
                    return false;
                }

            case ')': if (!st.empty() and st.top() == '(') {
                    st.pop();
                    break;
                } else {
                    return false;
                }

            }
        }
        return st.empty();
    }
};