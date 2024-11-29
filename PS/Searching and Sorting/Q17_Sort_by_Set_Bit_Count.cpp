class Solution {
public:
    static bool comp(int p, int q) {
        int a = __builtin_popcount(p);
        int b = __builtin_popcount(q);
        return a > b;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr + n, comp);
    }
};