class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double, Item> a, pair<double, Item> b) {
        return a.first > b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {   vector<pair<double, Item>> v;
        for (int i = 0; i < n; i++) {
            double perUnit = (1.0 * arr[i].value) / arr[i].weight;
            v.push_back({perUnit, arr[i]});
        }

        sort(v.begin(), v.end(), cmp);

        double total = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].second.weight > W) {
                total = total + W * v[i].first;
                W = 0;
            }
            else {
                total = total + v[i].second.value;
                W = W - v[i].second.weight;
            }
        }

        return total;
    }

};