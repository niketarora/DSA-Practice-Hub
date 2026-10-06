class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '['){
                st.push(s[i]);
            }else{
                if(st.empty() == false){
                    st.pop();
                } 
            }
        }
        int res = st.size();
        int ans = (res + 1)/2;
        return ans;
    }
};