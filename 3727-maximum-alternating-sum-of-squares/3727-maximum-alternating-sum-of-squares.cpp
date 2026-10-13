class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, -1);
        for(int i=0; i<n; i++){
            v[i] = nums[i]*nums[i];
        }
        sort(v.begin(), v.end());
        int i=0, j=n-1;
        long long sum = 0;
        while(i<=j){
            sum += v[j];
            j--;
            if(i>j)  break;
            sum -= v[i];
            i++;
        }
        return sum;
    }
};