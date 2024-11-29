class Solution {
public:
    int middle(int A, int B, int C) {
        long long int a = A;
        long long int b = B;
        long long int c = C;
        if ( (a - b) * (b - c) >= 0) {
            return b;
        } else if ( (b - a) * (a - c) >= 0 ) {
            return a;
        } else {
            return c;
        }
    }
};