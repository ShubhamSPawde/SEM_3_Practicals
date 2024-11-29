/*Given a string, we have to find out all its subsequences of it. A String is said to be a subsequence of another String, if it can be obtained by deleting 0 or more character without changing its order.*/

#include <bits/stdc++.h>
using namespace std;

void printSubRec(string s, string curr)
{
    if (s.empty()) {
        cout << curr << endl;
        return;
    }

    printSubRec(s.substr(1), curr + s[0]);
    printSubRec(s.substr(1), curr);
}

void printSubs(string s)
{
    string curr = ""; 
    printSubRec(s, curr);
}

int main()
{
    string s = "ab";
    printSubs(s); 
    return 0;
}
