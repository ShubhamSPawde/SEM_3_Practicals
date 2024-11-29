/*You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.
Note: The characters in the strings are in lowercase.*/


class Solution {
  public:    
    bool areRotations(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;

        return (s1 + s1).find(s2) != string::npos;
    }
};




class Solution {
  public:  
    bool areRotations(string& s1, string& s2) {
        string t = s1;
        do{
            if(t == s2){
                return true;
            }
        }while(next_permutation(t.begin(), t.end()));
        return false;
    }
};