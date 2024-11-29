class Solution {
public:
    vector<long long> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        long long totalProduct = 1;
        int zeroCount = 0;

        for (int j = 0; j < n; j++) {
            if (arr[j] != 0) {
                totalProduct *= arr[j];
            } else {
                zeroCount++;
            }
        }

        vector<long long> pro(n, 0);

        if (zeroCount > 1) {
            return pro;
        } else if (zeroCount == 1) {
            for (int i = 0; i < n; i++) {
                if (arr[i] == 0) {
                    pro[i] = totalProduct;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                pro[i] = totalProduct / arr[i];
            }
        }

        return pro;
    }
};