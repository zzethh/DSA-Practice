class Solution {
public:
    bool checkValidString(string s) {
        stack<int> opening;
        stack<int> star;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                opening.push(i);
            }
            else if (c == '*') {
                star.push(i);
            }
            else {
                if (!opening.empty()) {
                    opening.pop();
                } else {
                    if (!star.empty()) {
                        star.pop();
                    } else {
                        return false;
                    }
                }
            }
        }

        while (!opening.empty() and !star.empty()) {
            if (star.top() > opening.top()) {
                opening.pop();
                star.pop();
            } else {
                break;
            }
        }

        return opening.empty();
    }
};