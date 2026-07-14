#include<string>
class Solution {
public:
    bool isValid(string s) {
        stack <char> st;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
                continue;
            }

            if(st.empty()){
                return false;
            }

            if(s[i] == ')' && st.top() == '('){
                st.pop();
                continue;
            }
            
            else if(s[i] == ']' && st.top() == '['){
                st.pop();
                continue;
            }

            else if(s[i] == '}' && st.top() == '{'){
                st.pop();
                continue;
            }

            else{
                return false;
            }

        }
    
    return (st.empty() == true) ? true : false;
    }
};