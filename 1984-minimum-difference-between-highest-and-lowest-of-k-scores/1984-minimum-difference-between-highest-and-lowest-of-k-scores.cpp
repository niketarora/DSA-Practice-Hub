class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = k-1;
        int n = nums.size();
        int ans = INT_MAX;
        while(j<n){
            int min = nums[i];
            int max = nums[i];
            for(int itr=i; itr<=j; itr++){
                if(max<nums[itr]) 
                    max = nums[itr];
                if(min>nums[itr]) 
                    min = nums[itr];
            }
            int res = max - min;
            if(res<ans)
                ans = res;
            i++;
            j++;
        }
        return ans;
    }
};