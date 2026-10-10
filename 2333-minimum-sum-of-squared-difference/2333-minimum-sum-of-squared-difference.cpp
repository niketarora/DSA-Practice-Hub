class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        
        // Step 1: Calculate absolute differences and track the maximum difference
        int max_diff = 0;
        vector<int> diffs(n);
        for (int i = 0; i < n; ++i) {
            diffs[i] = abs(nums1[i] - nums2[i]);
            max_diff = max(max_diff, diffs[i]);
        }
        
        // If the maximum difference is already 0, no operations are needed
        if (max_diff == 0) return 0;
        
        // Step 2: Use a frequency array to count occurrences of each difference
        vector<int> counts(max_diff + 1, 0);
        for (int d : diffs) {
            counts[d]++;
        }
        
        // Step 3: Greedy reduction from the largest difference down to 1
        for (int d = max_diff; d > 0; --d) {
            if (counts[d] == 0) continue;
            
            // If our budget k can completely decrement all differences of size 'd' to 'd-1'
            if (k >= counts[d]) {
                k -= counts[d];
                counts[d - 1] += counts[d];
                counts[d] = 0;
            } 
            // If budget k is exhausted before we can convert all elements of size 'd'
            else {
                counts[d - 1] += k;
                counts[d] -= k;
                k = 0;
                break; // No operations left
            }
        }
        
        // Step 4: Calculate the final minimum sum of squared differences
        long long min_squared_sum = 0;
        for (long long d = 1; d <= max_diff; ++d) {
            if (counts[d] > 0) {
                min_squared_sum += (d * d) * counts[d];
            }
        }
        
        return min_squared_sum;
    }
};