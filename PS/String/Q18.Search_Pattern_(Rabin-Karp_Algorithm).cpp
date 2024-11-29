/*Given two strings, one is a text string and the other is a pattern string. The task is to print the starting indexes of all the occurrences of the pattern string in the text string. For printing, the Starting Index of a string should be taken as 1. The strings will only contain lowercase English alphabets ('a' to 'z').

Example 1:

Input: 
text = "birthdayboy"
pattern = "birth"
Output: [1]
Explanation: 
The string "birth" occurs at index 1 in text.*/


class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
           vector<int> ans;
            int n = text.length();
            int m = pattern.length();
            
            
            for(int i = 0; i <= n - m; i++) {
                if(text.substr(i, m) == pattern) {
                    ans.push_back(i + 1);  
                }
            }
            return ans;
        }
     
};