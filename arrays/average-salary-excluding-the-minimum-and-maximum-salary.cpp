class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double sum = 0;
        int cnt = 0;
        for (int i = 1; i < salary.size() - 1; i++) {
            sum += salary[i];
            cnt++;
        }
        return sum / cnt;
    }
};