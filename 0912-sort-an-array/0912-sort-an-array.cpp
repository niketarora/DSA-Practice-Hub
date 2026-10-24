class Solution {
public:
    void merge(int i, int j, vector<int> &nums){
        if (i >= j) return;
        int mid =  (i+j)/2;
        merge(i, mid, nums);
        merge(mid+1, j, nums);

        vector<int> temp;
        int left = i;
        int right = mid + 1;

        while (left <= mid && right <= j) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= j) {
            temp.push_back(nums[right]);
            right++;
        }
        for (int k = 0; k < temp.size(); k++) {
            nums[i + k] = temp[k];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        merge(i, j, nums);
        return nums;
    }
};