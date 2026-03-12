class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int s = nums.size();
        unordered_map<int,int> map;
        for(int i=0; i<s; i++){
            int rem = target - nums[i];
            if(map.find(rem) != map.end()){
                res.push_back(map[rem]);
                res.push_back(i);
            }
            else   map[nums[i]] = i;
        }
        return res;
    }
};