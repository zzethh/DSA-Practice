class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        set<pair<int, string>> s;
        for (int i = 0; i < names.size(); i++) {
            s.insert({heights[i], names[i]});
        }
        vector<string> v;
        for (auto i = s.rbegin(); i != s.rend(); i++) {
            v.push_back(i->second);
        }
        return v;
    }
};