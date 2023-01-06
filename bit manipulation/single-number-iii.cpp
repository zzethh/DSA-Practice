class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum ^ nums[i];
        }

        int cnt = 0;
        while (sum != 0) {
            int x = sum & 1;
            if (x) break;
            sum = sum >> 1;
            cnt++;
        }
        vector<int> one;
        vector<int> zero;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & (1 << cnt)) one.push_back(i);
            else zero.push_back(i);
        }

        //vector<int> ans;
        int a = 0;
        int b = 0;
        for (auto x : one) {
            a = a ^ nums[x];
        }
        for (auto y : zero) {
            b = b ^ nums[y];
        }

        return {a, b};

    }
};