class Solution {
public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                return i;
            }
        }
        return -1;
    }
};