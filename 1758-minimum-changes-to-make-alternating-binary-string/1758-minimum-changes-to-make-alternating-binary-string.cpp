class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string st = "";
        for(int i=0; i<n; i++){
            if(i%2)  st += '0';
            else  st += '1';
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(s[i] != st[i])   count++;
        }
        int res = min(count, n-count);
        
        return res;
    }
};