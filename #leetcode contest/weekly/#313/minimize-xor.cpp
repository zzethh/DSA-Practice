class Solution {
public:
    int setbits(int num2) {
        int cnt = 0;
        while (num2) {
            num2 = num2 & (num2 - 1);
            cnt++;
        }
        return cnt;
    }

    int minimizeXor(int num1, int num2) {
        int x = setbits(num2);
        cout << x << " ";
        vector<int> v;
        while (num1) {
            if (num1 & 1) {
                v.push_back(1);
            }
            else v.push_back(0);
            num1 = num1 >> 1;
        }
        for (auto x : v) {
            cout << x << " ";
        }
        vector<int> ans(v.size(), 0);
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] == 1 and x > 0) {
                ans[i] = 1;
                x--;
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (x > 0 and v[i] == 0) {
                ans[i] = 1;
                x--;
            }
            //else break;
        }
        while (x--) {
            ans.push_back(1);
        }
        cout << endl;
        for (auto x : ans) {
            cout << x << " ";
        }
        int prod = 1;
        int temp = 0;
        for (auto x : ans) {
            temp = temp + (prod * x);
            prod = prod * 2;
        }
        return temp;
    }
};