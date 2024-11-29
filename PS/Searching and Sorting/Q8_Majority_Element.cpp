class Solution {
public:
    int majorityElement(vector<int>& arr) {
        vector<int> v(1e5, 0);
        for (int i = 0; i < arr.size(); i++) {
            v[arr[i]]++;
        }

        for (int i = 0; i < v.size(); i++) {
            if ( v[i] > ( arr.size() / 2) ) {
                return i;
            }
        }
        return -1;
    }
};