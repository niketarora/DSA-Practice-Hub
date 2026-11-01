class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minele = INT_MAX;
        for(int i=0; i<n; i++){
            minele = min(minele, nums[i]);
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            if(minele == nums[i]) continue;
            else{
                sum += abs(nums[i] - minele);
            }
        }
        return sum;
    }
};