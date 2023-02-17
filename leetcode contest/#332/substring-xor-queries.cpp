class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> v;
        for (auto x : queries) {
            int temp = 0;
            for (auto y : x) {
                temp = temp ^ y;
            }
            string ans = "";
            if (temp == 0) ans = "0" + temp;
            while (temp) {
                int rem = temp % 2;
                if (rem) ans = "1" + ans;
                else ans = "0" + ans;
                temp = temp / 2;
            }
            int index = s.find(ans);
            if (index == -1) {
                v.push_back({ -1, -1});
            }
            else {
                int left = index;
                int right = index + ans.length() - 1;
                v.push_back({left, right});
            }
        }
        return v;
    }
};