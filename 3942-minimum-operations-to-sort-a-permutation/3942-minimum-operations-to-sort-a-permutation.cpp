class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        vector<int> v = nums;
        for (int i = 0; i < n; i++) {
            v.push_back(nums[i]);
        }

        int count = 1;
        for (int i = 1; i < 2 * n; i++) {
            if (v[i] < v[i - 1]) {
                count = 1;
            } else {
                count++;
                if (count == n) {
                    return (i + 1 - n) % n;
                }
            }
        }
        return -1;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = solve(nums);
        int ans = 1e9;
        if (k != -1) {
            ans = min(ans, k);
            ans = min(ans, n - k + 2);
        }
        reverse(nums.begin(), nums.end());
        int r = solve(nums);
        if (r != -1) {
            ans = min(ans, 1 + min(r, n - r));
        }
        return ans == 1e9 ? -1 : ans;
    }
};
