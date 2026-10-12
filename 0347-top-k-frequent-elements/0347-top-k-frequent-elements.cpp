class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(auto ele : nums){
            mp[ele]++;
        }
        vector<pair<int, int>> v;
        for(auto ele : mp){
            int first = ele.first;
            int second = ele.second;
            v.push_back({first, second});
        }
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};