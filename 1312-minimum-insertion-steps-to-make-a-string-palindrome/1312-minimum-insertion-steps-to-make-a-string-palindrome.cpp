class Solution {
public:
    int t[501][501];
    int func(int i, int j, string &s, int ans){
        if(i>=j)    return ans;
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(s[i] == s[j]){
            return t[i][j] = func(i+1, j-1, s, ans);
        }else{
            return t[i][j] = 1 + min(func(i+1, j, s, ans), func(i, j-1, s, ans));
        }
    }
    int minInsertions(string s) {
        int n = s.length();
        int ans = 0;
        memset(t, -1, sizeof(t));
        return func(0, n-1, s, ans);
    }
};