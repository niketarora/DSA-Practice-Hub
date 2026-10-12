class Solution {
public:
    void reversePart(int i, int j, vector<int> &a){
        while(i<=j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            reversePart(0, n-1, nums);
        }else{
            for(int j=n-1; j>idx; j--){
                if(nums[j] > nums[idx]){
                    swap(nums[j], nums[idx]);
                    break;
                }
            }
            reversePart(idx+1, n-1, nums);
        }
        return;
    }
};