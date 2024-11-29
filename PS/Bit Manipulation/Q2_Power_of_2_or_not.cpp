/*Given a non-negative integer n. The task is to check if it is a power of 2. */

class Solution {
public:
    bool isPowerofTwo(int n) {
        int cnt = 0;
        while (n != 0) {
            if (n & 1) {
                cnt++;
            }
            n = n >> 1;
        }
        return cnt == 1;
    }
};