class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int temp = target - nums[i];
            if(mp.find(temp) != mp.end()){
                int second = mp[temp];
                if(second > i){
                    ans.push_back(i);
                    ans.push_back(second);
                }
                else{
                    ans.push_back(second);
                    ans.push_back(i);
                }
            }else{
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};