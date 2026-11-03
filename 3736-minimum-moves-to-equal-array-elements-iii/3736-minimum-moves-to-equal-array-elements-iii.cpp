
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = nums[0];
        long long sum = 0;

        for (int x : nums) {
            mx = max(mx, x);
            sum += x;
        }

        return (long long)mx * nums.size() - sum;
    }
};
