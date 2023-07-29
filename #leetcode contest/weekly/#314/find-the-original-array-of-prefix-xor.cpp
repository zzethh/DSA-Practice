class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr;
        int x = 0;
        for (auto y : pref) {
            arr.push_back(x ^ y);
            x = y;
        }
        return arr;
    }
};