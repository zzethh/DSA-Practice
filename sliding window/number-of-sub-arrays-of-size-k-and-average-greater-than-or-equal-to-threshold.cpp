class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int thresh) {
        int sum = 0;
        int t = thresh * k;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int cnt = 0;
        if (sum >= t) cnt++;
        for (int i = k; i < arr.size(); i++) {
            sum += arr[i];
            sum -= arr[i - k];
            if (sum >= t) {
                cnt++;
            }
        }
        return cnt;
    }
};