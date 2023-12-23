class Solution {
public:
    int minProcessingTime(vector<int>& pt, vector<int>& t) {
        sort(t.begin(), t.end(), greater());
        sort(pt.begin(), pt.end());
        int n = pt.size();
        // vector<int> pref(t.size()+1,0);
        // for(int i=1;i<t.size();i++){
        //     pref[i-1]+=t[i];
        // }
        int j = 0;
        int ans = INT_MIN;
        for (int i = 0; i < pt.size(); i++) {
            cout << t[j] << " " << pt[i] << "--" << endl;
            int sum = t[j] + pt[i];
            ans = max(ans, sum);
            j = j + 4;
        }
        return ans;
    }
};