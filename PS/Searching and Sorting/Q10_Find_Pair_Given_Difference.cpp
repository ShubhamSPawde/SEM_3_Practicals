class Solution {
public:
    bool findPair(vector<int> &arr, int x) {
        sort(arr.begin(), arr.end());
        int s = 0;
        int e = 1;
        while (e < arr.size()) {
            int diff = arr[e] - arr[s];
            if (diff == x && s != e) {
                return true;
            }
            else if (diff < x) {
                e++;
            } else {
                s++;
                if (s == e) {
                    e++;
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool findPair(vector<int> &arr, int x) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if ( abs(arr[i] - arr[j]) == x ) {
                    return true;
                }
            }
        }
        return false;
    }
};