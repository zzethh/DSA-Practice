class Solution {
public:
    int minLength(string s) {
        while (true and s.length() >= 2) {
            bool flag = true;
            for (int i = 0; i < s.length() - 1; i++) {
                string str = s.substr(i, 2);
                cout << i << "->" << str << endl;
                if (str == "AB" or str == "CD") {
                    s.erase(i, 2);
                    flag = false;
                    break;
                }
            }
            if (flag) break;
        }
        return s.length();
    }
};