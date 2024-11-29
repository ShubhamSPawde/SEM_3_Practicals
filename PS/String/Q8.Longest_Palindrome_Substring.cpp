/*Given a string s, your task is to find the longest palindromic substring within s. A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).
A palindrome is a string that reads the same forward and backwards. More formally, s is a palindrome if reverse(s) == s.
Note: If there are multiple palindromes with the same length, return the first occurrence of the longest palindromic substring from left to right.*/

class Solution {
public:
    string longestPalindrome(string& s) {
        string res = "";
        int maxLen = -1;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (j - i + 1 > maxLen && isPalindrome(s, i , j)) {
                    maxLen = j - i + 1;
                    res = s.substr(i, maxLen);
                }
            }
        }
        return res;
    }


private:
    bool isPalindrome(string str, int s, int e) {
        while (s < e) {
            if (str[s] != str[e]) {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }

};