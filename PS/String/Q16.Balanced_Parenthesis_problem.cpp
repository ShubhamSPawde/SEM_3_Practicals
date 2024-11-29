/*Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).*/

class Solution {
  public:
    bool isParenthesisBalanced(string& s) {
        if(s.length() == 1) return false;
        stack<char> st;
        for(int i = 0; i<s.length(); i++){
            if(isOpeningB(s[i])){
                st.push(s[i]);
            }    
            else{
                if(st.empty() || st.top() != corresB(s[i])) {
                    return false; 
                }
                st.pop(); 
            }
        }
        return st.empty();
        
    }
    
    bool isOpeningB(char ch){
        return ch == '(' || ch == '[' || ch == '{';
    }
    char corresB(char ch){
        if(ch == ')') return '(';
        if(ch == '}') return '{';
        if(ch == ']') return '[';
    }
};
