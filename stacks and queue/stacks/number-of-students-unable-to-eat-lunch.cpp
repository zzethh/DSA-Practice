class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> s1;
        queue<int> s2;
        int count1 = 0;
        int count0 = 0;
        for (auto x : students) {
            if (x == 0) count0++;
            else count1++;
            s1.push_back(x);
        }
        for (auto c : sandwiches) {
            s2.push(c);
        }

        while (true) {
            if (s1.front() == s2.front() and s1.front() == 1) {
                s1.pop_front();
                s2.pop();
                count1--;
            }
            else if (s1.front() == s2.front() and s1.front() == 0) {
                s1.pop_front();
                s2.pop();
                count0--;
            }
            else {
                if (count1 == 0 or count0 == 0) {
                    break;
                }
                int a = s1.front();
                s1.pop_front();
                s1.push_back(a);
            }
        }

        // if(s1.empty()==1){
        //     return 0;
        // }

        return s1.size();
    }
};