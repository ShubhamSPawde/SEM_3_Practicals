class Solution {
public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int s = 0;
        vector<int> v(arr1.size() + arr2.size());
        for (int i = 0; i < arr1.size(); i++) {
            v[s++] = arr1[i];
        }
        for (int i = 0; i < arr2.size(); i++) {
            v[s++] = arr2[i];
        }
        sort(v.begin(), v.end());
        return v[k - 1];

    }
};