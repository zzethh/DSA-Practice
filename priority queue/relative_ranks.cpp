#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<vector<int>> pq;
        for (int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }

        int n = score.size();
        vector<string> answer(n);

        if (!pq.empty()) {
            auto first = pq.top();
            answer[first[1]] = "Gold Medal";
            pq.pop();
        }

        if (!pq.empty()) {
            auto second = pq.top();
            answer[second[1]] = "Silver Medal";
            pq.pop();
        }

        if (!pq.empty()) {
            auto third = pq.top();
            answer[third[1]] = "Bronze Medal";
            pq.pop();
        }

        int rank = 4;
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            answer[x[1]] = to_string(rank++);
        }
        return answer;
    }
};


int main() {



    return 0;
}

