class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        //unordered_set<int> s;
        unordered_map<long long, long long> m;
        for (auto x : skill) {
            sum += x;
            //s.insert(x);
        }
        long long n = skill.size();
        long long pairsum = (sum) / (n / 2);
        long double ps = (sum) / (n / 2);
        if (ps - pairsum != 0) return -1;
        long long cnt = 0;
        long long ans = 0;
        for (int i = 0; i < skill.size(); i++) {
            int target = pairsum - skill[i];
            if (m.find(target) == m.end()) {
                m[skill[i]]++;
            }
            else {
                cnt++;
                m[target]--;
                if (m[target] == 0) m.erase(target);
                ans += target * skill[i];
            }
        }

        if (cnt == skill.size() / 2) return ans;
        return -1;
    }
};