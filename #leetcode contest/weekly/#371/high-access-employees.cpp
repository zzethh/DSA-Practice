class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        map<string, vector<int>> mp;
        vector<string> v;
        for (auto x : at) {
            string key = x[0];
            string value = x[1];
            int i = 0;
            string hr = "";
            for (; i < 2; i++) {
                hr += value[i];
            }
            int h = stoi(hr);
            string min = "";
            for (; i < value.length(); i++) {
                min += value[i];
            }
            int m = stoi(min);
            int time = h * 60 + m;
            mp[x[0]].push_back(time);
            //cout<<time<<endl;
        }

        ///sort(mp.begin(),mp.end());
        // for(auto x:mp){
        //     cout<<x.first<<"->";
        //     sort(x.second.begin(),x.second.end());
        //     for(auto y:x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }

        for (auto x : mp) {
            for (int i = 0; i < x.second.size(); i++) {
                bool flag = false;
                int cnt = 0;
                sort(x.second.begin(), x.second.end());
                for (int j = i; j < x.second.size(); j++) {
                    //cout<<x.second[i]<<" "<<x.second[j]<<endl;
                    if (abs(x.second[j] - x.second[i]) < 60) {
                        cnt++;
                        if (cnt >= 3) {
                            // cout<<x.second[i]<<endl;
                            // cout<<i<<" "<<j<<endl;
                            // cout<<x.second[i]<<" "<<x.second[j]<<endl;
                            v.push_back(x.first);
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) break;
            }
        }
        return v;
    }
};