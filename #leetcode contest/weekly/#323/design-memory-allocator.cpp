class Allocator {
public:
    vector<int> v;
    //int left=0;
    //unordered_map<int,vector<int>> m;
    Allocator(int n) {
        v.resize(n, -1);
    }

    int allocate(int size, int mID) {
        //int left=0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == -1) {
                int left = i;
                if (left + size > v.size()) return -1;
                int len = 0;
                while (i < v.size() and v[i] == -1 and len < size) {
                    len++;
                    i++;
                }
                if (size == len) {
                    for (int j = left; j < left + size; j++) {
                        v[j] = mID;
                        //m[mID].push_back(j);
                    }
                    return left;
                }
            }
        }
        return -1;
    }

    int free(int mID) {
        // for(auto x:m[mID]){
        //     v[x]=0;
        // }
        // int ans=m[mID].size();
        // m.erase(mID);
        // return ans;
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == mID) {
                v[i] = -1;
                cnt++;
            }
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */