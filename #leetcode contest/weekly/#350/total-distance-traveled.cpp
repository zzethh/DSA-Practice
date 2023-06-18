class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int fuel = 0;
        while (mainTank) {
            if (mainTank - 5 >= 0) {
                mainTank -= 5;
                if (additionalTank) {
                    mainTank++;
                    additionalTank--;
                }
                fuel = fuel + 5 * 10;
            }
            else {
                fuel = fuel + mainTank * 10;
                mainTank = 0;
            }
        }
        return fuel;
    }
};