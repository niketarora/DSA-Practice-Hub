class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Check each possible block size k that divides n
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool possible = true;
            int prev_max = INT_MIN;

            // Iterate over each chunk of size k
            for (int i = 0; i < n; i += k) {
                int min_val = INT_MAX;
                int max_val = INT_MIN;
                int drop_count = 0;

                // Find global min/max for the chunk and check cyclic non-decreasing behavior
                for (int j = 0; j < k; ++j) {
                    min_val = min(min_val, nums[i + j]);
                    max_val = max(max_val, nums[i + j]);
                    
                    if (j > 0 && nums[i + j] < nums[i + j - 1]) {
                        drop_count++;
                    }
                }

                // If it drops more than once, it cannot be fixed with a single cyclic shift
                if (drop_count > 1) {
                    possible = false;
                    break;
                }

                // If it drops exactly once, the end of the chunk must be <= the start
                if (drop_count == 1 && nums[i + k - 1] > nums[i]) {
                    possible = false;
                    break;
                }

                // Ensure the current chunk's elements are all greater than or equal to the previous chunk's max
                if (min_val < prev_max) {
                    possible = false;
                    break;
                }

                prev_max = max_val;
            }

            if (possible) {
                ans += k;
            }
        }

        return ans;
    }
};