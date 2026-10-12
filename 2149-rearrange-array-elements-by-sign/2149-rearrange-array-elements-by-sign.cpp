class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> nev;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0) pos.push_back(nums[i]);
            else nev.push_back(nums[i]);
        }
        vector<int> v;
        int n = pos.size();
        for(int i=0; i<n; i++){
            v.push_back(pos[i]);
            v.push_back(nev[i]);
        }
        return v;
    }
};