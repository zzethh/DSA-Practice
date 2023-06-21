class Solution {
public:
    int closetTarget(vector<string>& words, string target, int s) {
        int i = s;
        int cnt1 = 0;
        int n = words.size();
        do {
            if (words[i % n] == target) {
                break;
            }
            // else{
            cnt1++;
            i++;
            // }
        } while (i % n != s);
        //cout<<i<<endl;
        // i--;
        if (i % n == s and words[i % n] != target) {
            cnt1 = INT_MAX;
        }
        cout << i % n << endl;
        cout << cnt1 << endl;
        int j = s;
        int cnt2 = 0;
        do {
            if (words[(j + n) % n] == target) {
                break;
            }
            //else{
            cnt2++;
            j--;
            //}
        } while ((j + n) % n != s);
        //j++;
        if ((j + n) % n == s and words[(j + n) % n] != target) {
            cnt2 = INT_MAX;
        }
        cout << (j + n) % n << endl;
        cout << cnt2 << endl;
        int ans = min(cnt1, cnt2);
        if (ans == INT_MAX) return -1;
        return ans;
    }
};