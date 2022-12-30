int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int res = 0;
    for (int i = 0; i < A.size(); i++)
    {
        unordered_map<double, int>mp;
        double x1 = (double)A[i], y1 = (double)B[i];
        int same = 0;
        for (int j = i + 1; j < B.size(); j++)
        {
            double x2 = (double)A[j], y2 = (double)B[j];
            if (x1 == x2 && y1 == y2) //for same points
            {
                same++;
            }
            else if (x2 == x1)
            {
                mp[INT_MAX]++;
            }
            else {
                double slope = (y2 - y1) / (x2 - x1);
                mp[slope]++;
            }
        }
        int temp = 0;
        for (auto x : mp)
        {
            // cout<<i<<" "<<x.first<<" "<<x.second<<endl;
            temp = max(temp, x.second);
        }
        temp++;
        temp = temp + same;
        res = max(res, temp);
    }
    return res;

}
