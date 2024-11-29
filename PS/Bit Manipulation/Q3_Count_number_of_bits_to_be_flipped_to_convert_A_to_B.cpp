/*You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.*/

class Solution {
public:
    int countBitsFlip(int a, int b) {

        int cnt = 0;
        while (a != 0 || b != 0) {
            if ((a & 1) != (b & 1)) {
                cnt++;
            }
            a = a >> 1;
            b = b >> 1;
        }

        return cnt;
    }
};