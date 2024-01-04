class Solution {
public:
    long long minimumSteps(string s) {
        vector<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') st.push_back(i);
        }
        long long cnt = 0;
        long long k = st.size() - 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (k < 0) break;
            if (s[i] == '1') {
                //cout<<i<<endl;
                auto f = find(st.begin(), st.end(), i);
                st.erase(f);
                k--;
                continue;
            }
            long long nidx = st[k];
            // cout<<i<<" "<<nidx<<endl;
            k--;
            cnt += (i - nidx);
            s[nidx] = '0';
            if (k < 0) break;
        }
        return cnt;
    }
};