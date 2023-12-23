class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0;
        int r = 0;
        int d = 0;
        for (int i = 0; i < moves.length(); i++) {
            if (moves[i] == 'L') l++;
            else if (moves[i] == 'R') r++;
            else d++;
        }
        cout << l << r << d << endl;
        if (l > r) return l - r + d;
        return r - l + d;
    }
};