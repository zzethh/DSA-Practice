class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans = "";
        for (char c : s) {
            if (c != ']') {
                st.push(c);
            }
            else {
                string str = "";
                while (!st.empty() and st.top() != '[') {
                    str = str + st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop();
                    string k = "";
                    while (!st.empty() and isdigit(st.top()))
                    {
                        k = k + st.top();
                        st.pop();
                    }
                    reverse(k.begin(), k.end());
                    int a = stoi(k);
                    // string k="";
                    // k= st.top() + k;
                    // int a=stoi(k);
                    //st.pop();
                    reverse(str.begin(), str.end());
                    while (a--) {
                        for (char x : str) {
                            st.push(x);
                        }
                    }
                }
            }
        }
        string m = "";
        while (!st.empty()) {
            m = m + st.top();
            st.pop();
        }
        reverse(m.begin(), m.end());
        return m;
    }
};