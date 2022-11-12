class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> map(27, 0);
        vector<bool> set(27, 0);
        for (int i = 0; i < s.length(); i++) {
            map[s[i] - 'a'] = i;
        }

        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (set[s[i] - 'a'] == 1) continue;

            while (!st.empty() and st.top() > s[i] and map[st.top() - 'a'] > i) {
                set[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            set[s[i] - 'a'] = 1;
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};