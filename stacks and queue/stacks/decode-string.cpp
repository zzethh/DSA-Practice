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
                    str = st.top() + str;
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop();
                    string k = "";
                    while (!st.empty() and isdigit(st.top()))
                    {
                        k = st.top() + k;
                        st.pop();
                    }
                    // reverse(k.begin(),k.end());
                    int a = stoi(k);
                    // string k="";
                    // k= st.top() + k;
                    // int a=stoi(k);
                    //st.pop();
                    // reverse(str.begin(),str.end());
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
            m = st.top() + m;
            st.pop();
        }
        // reverse(m.begin(),m.end());
        return m;
    }
};