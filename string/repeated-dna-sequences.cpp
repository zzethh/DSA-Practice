class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        vector<string> ans;
        for (int i = 0; i < s.length(); i++) {
            string seq = s.substr(i, 10);
            m[seq]++;
            if (m[seq] == 2) {
                ans.push_back(seq);
            }
        }
        return ans;
    }
};