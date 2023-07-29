class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr;
        int prev = 0;
        for (auto x : pref) {
            arr.push_back(x ^ prev);
            prev = x;
        }
        return arr;
    }
};