class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(n, -1);
        int cursum = 0;

        for(int i = 0; i < n; i++){
            cursum += nums[i];
            v[i] = cursum;
        }

        int j = 0;
        unordered_map<int, int> mp;
        int count = 0;

        while(j < n){
            if(v[j] == k) count++;

            int val = v[j] - k;
            if(mp.find(val) != mp.end()){
                count += mp[val];
            }

            mp[v[j]]++;

            j++;
        }

        return count;
    }
};