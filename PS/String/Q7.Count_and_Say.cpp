/*Given a positive integer n, return the nth element of the count-and-say sequence.

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"*/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";

        string s = "11";
        for(int i = 3; i<=n; i++){
            string t = "";
            s += "$";
            int cnt = 1;
            for(int j = 1; j<s.length(); j++){
                if(s[j] != s[j-1]){
                    t += to_string(cnt);
                    t += s[j-1];
                    cnt = 1;
                }else cnt++;
            }
            s = t;
        }
        return s;
    }
};