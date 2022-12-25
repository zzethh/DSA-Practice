/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class compare {
public:
	bool operator()(Interval a, Interval b) {
		return a.start < b.start;
	}
};
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector<Interval> s(intervals.begin(), intervals.end());
	if (newInterval.start > newInterval.end) {
		Interval temp(newInterval.end, newInterval.start);
		s.push_back(temp);
	}
	else s.push_back(newInterval);
	sort(s.begin(), s.end(), compare());
	vector<Interval> ans;
	int st = s[0].start;
	int e = s[0].end;
	for (int i = 0; i < s.size(); i++) {
		if (s[i].start <= e) {
			e = max(s[i].end, e);
		}
		else {
			Interval temp(st, e);
			ans.push_back(temp);
			st = s[i].start;
			e = s[i].end;
		}
	}
	Interval temp(st, e);
	ans.push_back(temp);
	return ans;

}
