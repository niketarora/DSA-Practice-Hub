class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int count = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(st.empty() == 1){
                    if(s[i+1] == ')'){
                        count++;
                        i++;
                    }else{
                        count += 2;
                    }
                }else{
                    if(i<n-1 && s[i + 1] == ')'){
                        st.pop();
                        i++;
                    }else{
                        st.pop();
                        count++;
                    }
                }
            }
        }
        if(st.empty() == 0){
            count += st.size()*2;
        }
        return count;
    }
};