class Solution {
public:
    // int ans=INT_MAX;
    // int helper(string s,int x,int y,int z,string prev){
    //     if(prev="" or (x and prev[i]==prev){
    //         helper(s+"AA",x-1,y,z);
    //     }
    // }
    int longestString(int x, int y, int z) {
        string a = "AA";
        string b = "BB";
        string ab = "AB";
        string s = "";
        while (x != 0 and y != 0 and z != 0) {
            s += a;
            x--;
            s += b;
            y--;
            s += ab;
            z--;
        }
        // cout<<y;
        while (x != 0 and y != 0) {
            // cout<<"hellp";
            s += a;
            x--;
            s += b;
            y--;
        }
        // if(z!=0 and x!=0){
        //     s+=ab;
        //     s+=a;
        //     z--;
        //     x--;
        // }
        //cout<<x;
        while (z != 0) {
            s += ab;
            z--;
        }
        if (x) {
            s += a;
        }
        if (y) {
            s = b + s;
        }
        cout << s;
        return s.length();
    }
};