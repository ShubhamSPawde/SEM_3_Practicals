class Solution {
public:
    int pivot(vector<int>& arr, int s, int e) {
        int mid = s + (e - s) / 2;
        while (s < e) {
            mid = s + (e - s) / 2;
            if (arr[0] <= arr[mid]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }

    int binarysearch(vector<int> arr, int s, int e, int k) {
        int mid = s + (e - s) / 2;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (arr[mid] == k) {
                return mid;
            } else if (arr[mid] > k) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        if (nums.size() == 1 && target == nums[0])
            return 0;

        int pivotIndex = pivot(nums, 0, nums.size() - 1);

        if (target >= nums[pivotIndex] && target <= nums[nums.size() - 1]) {
            return binarysearch(nums, pivotIndex, nums.size() - 1, target);
        } else {
            return binarysearch(nums, 0, pivotIndex - 1, target);
        }
        return -1;
    }
};