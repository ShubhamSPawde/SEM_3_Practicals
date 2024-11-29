/*Given a positive integer n. Your task is to return the count of set bits.*/

class Solution {
public:
    int setBits(int n) {
        int m = n;
        int cnt = 0;
        while (m != 0) {
            if (m & 1) {
                cnt++;
            }
            m = m >> 1;
        }
        return cnt;
    }
};