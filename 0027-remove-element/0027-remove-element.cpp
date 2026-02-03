class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        while(i<j){
            while(i<n && i<j){
                if(nums[i]==val)    break;
                i++;
            }
            while(j>0 && i<j){
                if(nums[j]!=val)    break;
                j--;
            }
            if(i>=j) break;
            swap(nums[i], nums[j]);
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != val)  count++;
        }
        return count;
    }
};