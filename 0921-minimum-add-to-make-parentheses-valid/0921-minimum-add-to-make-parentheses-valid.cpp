class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(st.empty() == true){
                    ans++;
                }else{
                    st.pop();
                }
            }
        }
        if(st.empty() == false){
            ans += st.size();
        }
        return ans;
    }
};