class Solution {
public:
    int hashi(string s) {
        vector<int> f(27, 0);
        for (auto c : s) {
            if (f[c - 'a']) continue;
            f[c - 'a']++;
        }
        int sum = 0;
        int mul = 1;
        for (int i = 26; i >= 0; i--) {
            sum = sum + f[i] * mul;
            mul = mul * 2;
        }
        return sum;
    }

    int maxProduct(vector<string>& words) {
        vector<int> v;
        int ans = 0;
        for (auto x : words) {
            v.push_back(hashi(x));
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (v[i]&v[j]) continue;
                else {
                    int x = words[i].length();
                    int y = words[j].length();
                    ans = max(ans, x * y);
                }
            }
        }

        return ans;
    }
};