class Solution {
public:
    int cost(int a, int b, int c, int d) {
        return abs(a - c) + abs(b - d);
    }
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        set<pair<int, int>> s;
        set<pair<int, int>> st;
        map<pair<int, int>, int> idx;

        st.insert({start[0], start[1]});
        st.insert({target[0], target[1]});

        for (auto x : specialRoads) {
            st.insert({x[0], x[1]});
            st.insert({x[2], x[3]});
        }

        int in = 0;
        for (auto x : st) {
            idx[x] = in++;
        }

        list<pair<int, int> > *l2;
        l2 = new list<pair<int, int> >[in];


        int src = idx[ {start[0], start[1]}];
        int dest = idx[ {target[0], target[1]}];

        l2[src].push_back({cost(start[0], start[1], target[0], target[1]), dest});

        for (auto x : specialRoads) {
            l2[src].push_back({cost(x[0], x[1], start[0], start[1]), idx[{x[0], x[1]}]});
            l2[idx[ {x[0], x[1]}]].push_back({x[4], idx[{x[2], x[3]}]});
            l2[idx[ {x[2], x[3]}]].push_back({cost(x[2], x[3], target[0], target[1]), dest});

            for (auto y : specialRoads) {
                if (y == x) continue;

                int spo = idx[ {y[0], y[1]}];
                int spe = idx[ {y[2], y[3]}];

                int cost1 = cost(x[2], x[3], y[0], y[1]);
                int cost2 = cost(x[0], x[1], y[2], y[3]);

                l2[idx[ {x[2], x[3]}]].push_back({cost1, spo});
                l2[spe].push_back({cost2, idx[{x[0], x[1]}]});
            }
        }

        vector<int> dist(in, INT_MAX);
        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty()) {
            auto it = s.begin();
            int node = it->second;
            int disttillnow = it->first;
            s.erase(it);

            for (auto nbrPair : l2[node]) {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if (disttillnow + currentEdge < dist[nbr]) {
                    auto f = s.find({dist[nbr], nbr});

                    if (f != s.end()) {
                        s.erase(f);
                    }

                    dist[nbr] = disttillnow + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        return dist[dest];
    }
};