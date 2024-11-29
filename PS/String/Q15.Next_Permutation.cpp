/*Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). */

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        next_permutation(arr.begin(), arr.end());
    }
};