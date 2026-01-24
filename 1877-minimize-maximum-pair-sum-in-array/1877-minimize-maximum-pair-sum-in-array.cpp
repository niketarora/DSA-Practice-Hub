class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0; 
        int j = n-1;
        int max = INT_MIN;
        for(int k=0; k<n/2; k++){
            int sum = nums[i] + nums[j];
            if(max<sum) 
                max = sum;
            i++;
            j--;
        }
        return max;
    }
};