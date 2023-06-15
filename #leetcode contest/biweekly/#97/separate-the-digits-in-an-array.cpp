class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        stack<int> s;
        for (auto x : nums) {
            while (x != 0) {
                int digit = x % 10;
                s.push(digit);
                /// ans.push_back(digit);
                x = x / 10;
            }
            while (!s.empty()) {
                ans.push_back(s.top());
                s.pop();
            }
        }
        return ans;
    }
};