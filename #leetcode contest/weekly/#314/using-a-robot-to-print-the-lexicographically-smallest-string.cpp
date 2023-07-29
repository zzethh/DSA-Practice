class Solution {
public:
        char getmin(vector<int> freq) {
                for (int i = 0; i < 26; i++) {
                        if (freq[i] != 0) {
                                return (char)(i + 'a');
                        }
                }
                return 'A';
        }
        string robotWithString(string s) {
                int l = s.length();
                vector<int> freq(26, 0);
                for (int i = 0; i < l; i++) {
                        freq[s[i] - 'a']++;
                }
                stack<char> st;
                string ans = "";
                for (int i = 0; i < s.length(); i++) {
                        st.push(s[i]);
                        freq[s[i] - 'a']--;
                        while (!st.empty() and st.top() <= getmin(freq)) {
                                ans += st.top();
                                st.pop();
                        }
                }
                while (!st.empty()) {
                        ans += st.top();
                        st.pop();
                }
                return ans;
        }
};