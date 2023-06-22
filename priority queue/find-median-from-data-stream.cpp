class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    double med;
    int cnt = 0;
    MedianFinder() {
    }

    void addNum(int num) {
        if (cnt == 0) {
            cnt++;
            med = num;
            maxi.push(num);
            return;
        }
        if (maxi.size() > mini.size()) {
            if (num < med) {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(num);
            }
            else {
                mini.push(num);
            }
            double a = mini.top();
            double b = maxi.top();
            med = (a + b) / 2;
        }
        else if (maxi.size() == mini.size()) {
            if (num < med) {
                maxi.push(num);
                med = maxi.top();
            }
            else {
                mini.push(num);
                med = mini.top();
            }
        }
        else {
            if (num < med) {
                maxi.push(num);
            }
            else {
                maxi.push(mini.top());
                mini.pop();
                mini.push(num);
            }
            double a = mini.top();
            double b = maxi.top();
            med = (a + b) / 2;
        }
    }

    double findMedian() {
        MedianFinder();
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */