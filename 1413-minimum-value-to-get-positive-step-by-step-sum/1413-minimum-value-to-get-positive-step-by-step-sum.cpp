class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            sum += nums[i];
            nums[i] = sum;
        }
        int minele = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            minele = min(minele, nums[i]);
        }
        return minele<0 ? abs(-minele + 1) : 1;
    }
};