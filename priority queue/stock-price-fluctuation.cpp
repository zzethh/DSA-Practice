class StockPrice {
public:
    map<int, int> record;
    map<int, int> count;
    StockPrice() {

    }

    void update(int timestamp, int price) {
        if (record.find(timestamp) != record.end()) {
            count[record[timestamp]]--;
            if (count[record[timestamp]] == 0) count.erase(record[timestamp]);
        }
        record[timestamp] = price;
        count[price]++;
    }

    int current() {
        auto it = record.end();
        it--;
        return it->second;
    }

    int maximum() {
        auto it = count.end();
        it--;
        return it->first;
    }

    int minimum() {
        auto it = count.begin();
        return it->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */