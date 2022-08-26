class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int farray[26] = {0};
        for (int i = 0; i < tasks.size(); i++) {
            farray[tasks[i] - 'A']++;
        }

        sort(farray, farray + 26);

        int maxfreq = farray[25];
        int freeslots = (maxfreq - 1) * n;

        for (int i = 24; i >= 0; i-- ) {
            freeslots -= min(maxfreq - 1, farray[i]);
        }

        if (freeslots < 0) {
            freeslots = 0;
        }
        return freeslots + tasks.size();
    }
};