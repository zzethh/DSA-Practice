class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            int k;
            for (k = i + 1; k < arr.size(); k++) {
                val = val ^ arr[k];
                if (val == 0) cnt = cnt + (k - i);
            }
        }

        return cnt;
    }
};