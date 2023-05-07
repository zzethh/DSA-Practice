class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> left;
        vector<int> right(n, 0);
        unordered_map<int, int> m;
        unordered_map<int, int> m2;
        int cnt = 0;
        for (auto x : nums) {
            m[x]++;
            if (m[x] == 1) {
                cnt++;
                left.push_back(cnt);
            }
            else {
                left.push_back(cnt);
            }
        }
        int cnt2 = 0;
        for (int i = n - 2; i >= 0; i--) {
            m2[nums[i + 1]]++;
            if (m2[nums[i + 1]] == 1) {
                cnt2++;
                right[i] = cnt2;
            }
            else {
                right[i] = cnt2;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << left[i] << " " << right[i] << "->";
            ans.push_back(left[i] - right[i]);
        }
        cout << endl;
        return ans;
    }
};