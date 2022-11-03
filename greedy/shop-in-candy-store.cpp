class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int> ans;
        sort(candies, candies + N);

        int i = 0;
        int j = N - 1;
        int min = 0;
        while (i <= j) {
            min = min + candies[i];
            int cnt = K;
            while (cnt) {
                j--;
                cnt--;
            }
            i++;
        }
        ans.push_back(min);

        i = 0;
        j = N - 1;
        int max = 0;
        while (i <= j) {
            max = max + candies[j];
            int cnt = K;
            while (cnt) {
                i++;
                cnt--;
            }
            j--;
        }
        ans.push_back(max);

        return ans;
    }
};