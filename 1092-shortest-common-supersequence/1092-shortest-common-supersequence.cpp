class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> t(m+1, vector<int> (n+1, -1));
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==0 || j==0)    t[i][j] = i+j;
                else if(s1[i-1] == s2[j-1]) t[i][j] = 1 + t[i-1][j-1];
                else    t[i][j] = 1 + min(t[i-1][j], t[i][j-1]);
            }
        }
        string ans = "";
        int i=m, j=n;
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                ans = s1[i-1] + ans;
                i--; j--;
            }
            else{
                if(t[i-1][j] < t[i][j-1]){
                    ans = s1[i-1] + ans;
                    i--;
                }
                else{
                    ans = s2[j-1] + ans;
                    j--;
                }
            }
        }
        while(i>0){
            ans = s1[i-1] + ans;
            i--;
        }
        while(j>0){
            ans = s2[j-1] + ans;
            j--;
        }
        return ans;
    }
};