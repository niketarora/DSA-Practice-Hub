class Solution {
public:
    static bool cmp(pair<char, int> &a , pair<char,int> &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto ele : s) mp[ele]++;
        
        vector<pair<char, int>> vp;
        for(auto &p : mp) vp.push_back(p);

        sort(vp.begin(), vp.end(), cmp);
        
        string res = "";
        for(auto &x : vp){
            for (int i = 0; i < x.second; i++) {
                res += x.first;
            }
        }

        return res;
    }
};