class Solution {
public:
    int minimizedStringLength(string s) {
        set<char> st;
        for (auto x : s) {
            st.insert(x);
        }
        return st.size();
    }
};