class Solution {
public:
    vector<int> valueEqualToIndex(vector<int>& arr) {
        vector<int> v;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == i + 1 ) {
                v.push_back(arr[i]);
            }
        }
        return v;
    }
};