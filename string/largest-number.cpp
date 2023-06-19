class Solution {
public:
    bool static compare(string s1, string s2) {
        string a = (s1 + s2);
        string b = (s2 + s1);
        return a > b;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (auto x : nums) {
            v.push_back(to_string(x));
        }
        sort(v.begin(), v.end(), compare);
        string t = "";
        for (auto x : v) {
            t = t + x;
        }
        int i = 0;
        while (t[i] == '0' and i < t.length() - 1) {
            i++;
        }
        //int ans=stoi(t);
        return t.substr(i);
    }
};