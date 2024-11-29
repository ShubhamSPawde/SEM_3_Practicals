class Solution {
public:
    vector<int> find(vector<int> arr, int x) {
        int fOcc = -1, lOcc = -1;
        vector<int> v;
        fOcc = firstOcc(arr, x);
        lOcc = lastOcc(arr, x);
        v.push_back(fOcc);
        v.push_back(lOcc);
        return v;
    }

    int firstOcc(vector<int> arr, int x) {
        int s = 0;
        int ans = -1;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;
        while (s <= e) {
            if (arr[mid] == x) {
                ans = mid;
                e = mid - 1;
            }
            else if (arr[mid] > x) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }

    int lastOcc(vector<int> arr, int x) {
        int s = 0;
        int ans = -1;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;
        while (s <= e) {
            if (arr[mid] == x) {
                ans = mid;
                s = mid + 1;
            }
            else if (arr[mid] > x) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }


};