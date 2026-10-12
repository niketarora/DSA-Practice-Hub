class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        int ans = 0;
        for(auto ele : s){
            if(s.find(ele - 1) != s.end()){
                continue;
            }else{
                int count = 0;
                int curr = ele;
                while(s.find(curr) != s.end()){
                    count++;
                    curr++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};