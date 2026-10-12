class Solution {
public:
    static bool cmp(pair<char, int> &a , pair<char,int> &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for(auto ele : s)  mp[ele]++;
        vector<pair<char, int>> v;
        for(auto ele : mp){
            char first = ele.first;
            int second = ele.second;
            v.push_back({first, second});
        }
        sort(v.begin(), v.end(), cmp);
        string ans = "";
        
        for(auto ele : v){
            for(int i = 0; i < ele.second; i++){
                ans += ele.first;
            }
        }

        return ans;
    }
};