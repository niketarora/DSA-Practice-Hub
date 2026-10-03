class Solution {
public:
    int m,n;
    int t[501][501];
    int solve(string &w1, string &w2, int i, int j){
        if(i == m){
            return n-j;
        }
        else if(j == n){
            return m-i;
        }
        if(t[i][j] != -1)   return t[i][j];
        // insertion
        if(w1[i] == w2[j]){
            return t[i][j] = solve(w1, w2, i+1, j+1);
        }
        int insert = 1 + solve(w1, w2, i, j+1);
        int del = 1 + solve(w1, w2, i+1, j);
        int replace = 1 + solve(w1, w2, i+1, j+1);

        return t[i][j] = min(insert, min(del, replace));
    }
    int minDistance(string w1, string w2) {
        m=w1.length(), n=w2.length();
        int i = 0, j = 0;
        memset(t, -1, sizeof(t));
        return solve(w1, w2, i, j);
    }
};