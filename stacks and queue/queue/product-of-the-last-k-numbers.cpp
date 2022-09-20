class ProductOfNumbers {
public:
    vector<int> v;
    stack<int> s;
    int product = 1;
    ProductOfNumbers() {

    }

    void add(int num) {
        int index = v.size();
        if (num == 0) {
            v.push_back(1);
            s.push(index);
            product = 1;
        }
        else {
            product = product * num;
            v.push_back(product);
        }
    }

    int getProduct(int k) {
        int n = v.size();
        if (!s.empty()) {
            if (k >= n - s.top()) {
                return 0;
            }
        }
        if (n == k) {
            return v.back();
        }
        return v.back() / v[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */