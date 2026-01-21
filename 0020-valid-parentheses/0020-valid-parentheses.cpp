class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0)   return false;
        stack<char> st;
        int i = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
                continue;
            }
            if(s[i] == ')'){
                if(st.top() == '(') st.pop();
                else return false;
            } else if(s[i] == '}'){
                if(st.top() == '{') st.pop();
                else return false;
            } else if(s[i] == ']'){
                if(st.top() == '[') st.pop();
                else return false;
            }
        }
        if(st.size() != 0)    return false;
        return true;
    }
};