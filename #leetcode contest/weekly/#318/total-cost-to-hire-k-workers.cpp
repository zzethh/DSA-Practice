class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        int n = costs.size();
        if (c + c >= n) {
            sort(costs.begin(), costs.end());
            int sum = 0;
            for (int i = 0; i < k; i++) {
                sum += costs[i];
            }
            return sum;
        }
        vector<bool> v(n, false);
        set<pair<int, int>> left;
        set<pair<int, int>> right;
        for (int i = 0; i < c; i++) {
            left.insert({costs[i], i});
            v[i] = true;
            //cout<<i<<" ";
        }
        for (int i = n - 1; i >= n - c; i--) {
            if (v[i] == false) {
                right.insert({costs[i], i});
                v[i] = true;
                // cout<<i<<" ";
            }
        }
        long long sum = 0;
        int t = k;
        int i = c;
        int j = n - c - 1;
        //cout<<j;
        while (t--) {
            long long era;
            long long val;
            if (left.empty() and right.empty()) {
                return sum;
            }
            else if (left.empty()) {
                auto r = right.begin();
                val = r->first;
                era = r->second;
                sum += r->first;
                right.erase(r);
                if (v[j] == false) {
                    right.insert({costs[j], j});
                    v[j] = true;
                    j--;
                }
                continue;
            }
            else if (right.empty()) {
                auto l = left.begin();
                val = l->first;
                era = l->second;
                sum += l->first;
                left.erase(l);
                if (v[i] == false) {
                    left.insert({costs[i], i});
                    v[i] = true;
                    i++;
                }
                continue;
            }
            auto l = left.begin();
            auto r = right.begin();
            if (l->first <= r->first) {
                val = l->first;
                era = l->second;
                sum += l->first;
                left.erase(l);
                if (v[i] == false) {
                    left.insert({costs[i], i});
                    v[i] = true;
                    i++;
                }

            }
            else {
                val = r->first;
                era = r->second;
                sum += r->first;
                right.erase(r);
                if (v[j] == false) {
                    right.insert({costs[j], j});
                    v[j] = true;
                    j--;
                }
            }
            //cout<<"val "<<val<<" era "<<era<<endl;

        }
        return sum;
    }
};