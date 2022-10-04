class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = i - 1;
        int r = i;
        vector<int> v;

        int cnt = k;
        while (l >= 0 and r < arr.size()) {
            if (cnt == 0) break;

            if (abs(arr[l] - x) < abs(arr[r] - x)) {
                v.push_back(arr[l]);
                l--;
            }
            else if (abs(arr[l] - x) > abs(arr[r] - x)) {
                v.push_back(arr[r]);
                r++;
            }
            else {
                if (arr[l] < arr[r]) {
                    v.push_back(arr[l]);
                    l--;
                }
                else {
                    v.push_back(arr[r]);
                    r++;
                }
            }
            cnt--;
        }



        for (int j = 1; j <= cnt; j++) {
            if (r < arr.size()) {
                v.push_back(arr[r]);
                r++;
            }
            else if (l >= 0) {
                v.push_back(arr[l]);
                l--;
            }
        }

        sort(v.begin(), v.end());
        return v;
    }
};