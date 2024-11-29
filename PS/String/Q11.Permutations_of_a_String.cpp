/*Given a string s. The task is to return a vector of string of all unique permutations of the given string, s that may contain duplicates in lexicographically sorted order. */

class Solution {
  public:
    vector<string> findPermutation(string &s) {
       sort(s.begin(), s.end());
       vector<string> ans;
       do{
            ans.push_back(s);
       }while(next_permutation(s.begin(), s.end()));
       return ans;
    }
};