class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int grp) {
		if (hand.size() % grp) return false;
		priority_queue<int, vector<int>, greater<int>> pq;
		sort(hand.begin(), hand.end());
		map<int, int> m;
		for (auto x : hand) {
			m[x]++;
		}
		int prev = -1;
		for (auto x : hand) {
			if (prev == -1 or x != prev) {
				cout << x << " ";
				pq.push(x);
			}
			prev = x;
		}
		while (!pq.empty()) {
			int curr = pq.top();
			for (int i = curr; i < curr + grp; i++) {
				if (!m.count(i)) {
					return false;
				}
				m[i]--;
				if (m[i] == 0) {
					if (i != pq.top()) {
						return false;
					}
					m.erase(i);
					pq.pop();
				}
			}
		}
		return true;
	}
};