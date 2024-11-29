class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int missing = -1;
        int repeating = -1;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == arr[i + 1]) {
                repeating = arr[i];
                break;
            }
        }
        auto it = unique(arr.begin(), arr.end());
        arr.erase(it, arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != i + 1) {
                missing = i + 1;
                break;
            }
        }
        if (missing == -1 && arr.size() < arr.size() + 1) {
            missing = arr.size() + 1;
        }
        vector<int> v;
        v.push_back(repeating);
        v.push_back(missing);
        return v;
    }
};