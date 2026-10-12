class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m)  return false;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for(auto ele : s){
            mp1[ele]++;
        }
        for(auto ele : t){
            mp2[ele]++;
        }
        for(auto ele : mp1){
            char ch1 = ele.first;
            int freq1 = ele.second;
            if(mp2.find(ch1) != mp2.end()){
                int freq2 = mp2[ch1];
                if(freq1 != freq2) return false;
            }else   return false;
        }
        return true;
    }
};