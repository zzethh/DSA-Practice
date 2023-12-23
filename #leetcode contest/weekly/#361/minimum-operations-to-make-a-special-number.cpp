class Solution {
public:
    bool check(string nums, int target, int n) {
        for (int i = 0; i < n; i++) {
            if ((nums[i] - '0') == target) return true;
        }
        return false;
    }

    int give(string nums, int target, int n) {
        for (int i = n - 1; i >= 0; i--) {
            if ((nums[i] - '0') == target) {
                return i;
            }
        }
        return 0;
    }
    int minimumOperations(string num) {
        int n = num.length();
        int mini = n;
        for (int i = 1; i < num.length(); i++) {
            int x = num[i] - '0';
            int cnt = n;
            if (x == 0) {
                if (check(num, 0, i)) {
                    cout << i << " " << give(num, 0, i) << " ";
                    cnt = i - give(num, 0, i) - 1 + (n - 1 - i);
                    cout << cnt << " ";
                }
                mini = min(mini, cnt);
                if (check(num, 5, i)) {
                    cout << i << " " << give(num, 5, i) << " ";
                    cnt = i - give(num, 5, i) - 1 + (n - 1 - i);
                    cout << cnt << " ";
                }
                mini = min(mini, cnt);
            }
            if (x == 5) {
                if (check(num, 2, i)) {
                    cout << i << " " << give(num, 2, i) << " ";
                    cnt = i - give(num, 2, i) - 1 + (n - 1 - i);
                    cout << cnt << " ";
                }
                mini = min(mini, cnt);
                if (check(num, 7, i)) {
                    cout << i << " " << give(num, 7, i) << " ";
                    cnt = i - give(num, 7, i) - 1 + (n - 1 - i);
                    cout << cnt << " ";
                }
                mini = min(mini, cnt);
            }
            //cout<<endl;
        }
        if (mini == n) {
            for (int i = 0; i < n; i++) {
                if (num[i] - '0' == 0) {
                    return n - 1;
                }
            }
        }
        return mini;
    }
};