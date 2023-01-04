class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for (int i = 0; i < encoded.size(); i++) {
            int x = ans.back();
            int y = ans.back()^encoded[i];
            ans.push_back(y);
        }
        return ans;
    }
};