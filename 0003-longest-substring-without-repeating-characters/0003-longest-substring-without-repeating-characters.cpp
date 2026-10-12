class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        unordered_map<char, int> mp;
        int i=0, j=0;
        while(j < n){
            int len = 0;
            if(mp.find(s[j]) == mp.end()){
                mp[s[j]] = j;
            }else{
                int idx = mp[s[j]];
                if(idx >= i){
                    i = idx + 1;
                }
                mp[s[j]] = j;
            }
            len = j-i+1;
            maxlen = max(maxlen, len);
            j++;
        }
        return maxlen;
    }
};