class Solution {
public:
    int minimumPartition(string s, int k) {
        string t = "";
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            t += s[i];
            //cout<<t<<endl;
            if (stol(t) > k) {
                //cout<<"yo";
                if (t.length() == 1) return -1;
                // cout<<t<<endl;
                cnt++;
                t = s[i];
                //cout<<t<<endl;
                if (stol(t) > k) return -1;
            }
        }
        return cnt + 1;
    }
};