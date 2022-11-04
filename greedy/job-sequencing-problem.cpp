class Solution
{
public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b) {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);

        int maxDeadline = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(arr[i].dead, maxDeadline);
        }

        vector<int> deadline(maxDeadline + 1, -1);

        int count = 0;
        int maxprofit = 0;
        for (int i = 0; i < n; i++) {
            int currProfit = arr[i].profit;
            int currJobID = arr[i].id;
            int currDead = arr[i].dead;

            for (int k = currDead; k > 0; k--) {
                if (deadline[k] == -1) {
                    count++;
                    maxprofit += currProfit;
                    deadline[k] = currJobID;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(maxprofit);
        return ans;
    }
};