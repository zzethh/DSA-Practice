class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int tail = 0;
        int cnt = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == 0) cnt++;
            while (cnt > 1) {
                if (A[tail] == 0) cnt--;
                tail++;
            }
            maxi = max(maxi, i - tail);
        }

        return maxi;
    }
};

//https://www.youtube.com/watch?v=Jzy1COg8a34&ab_channel=CodingSamurai%27s