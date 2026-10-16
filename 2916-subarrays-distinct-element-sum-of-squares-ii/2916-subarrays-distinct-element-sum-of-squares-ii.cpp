class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;

        vector<long long> sum(4 * n, 0);
        vector<long long> sq(4 * n, 0);
        vector<int> lazy(4 * n, 0);

        auto update = [&](auto&& self, int node, int l, int r,
                          int ql, int qr) -> void {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                long long len = r - l + 1;
                sq[node] = (sq[node] + 2LL * sum[node] + len) % MOD;
                sum[node] = (sum[node] + len) % MOD;
                lazy[node]++;
                return;
            }

            int mid = (l + r) / 2;

            if (lazy[node]) {
                int v = lazy[node];

                sq[node * 2] =
                    (sq[node * 2] +
                     2LL * v * sum[node * 2] +
                     1LL * v * v * (mid - l + 1)) % MOD;

                sum[node * 2] =
                    (sum[node * 2] +
                     1LL * v * (mid - l + 1)) % MOD;

                lazy[node * 2] += v;

                sq[node * 2 + 1] =
                    (sq[node * 2 + 1] +
                     2LL * v * sum[node * 2 + 1] +
                     1LL * v * v * (r - mid)) % MOD;

                sum[node * 2 + 1] =
                    (sum[node * 2 + 1] +
                     1LL * v * (r - mid)) % MOD;

                lazy[node * 2 + 1] += v;
                lazy[node] = 0;
            }

            self(self, node * 2, l, mid, ql, qr);
            self(self, node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;

            update(update, 1, 0, n - 1, prev + 1, i);

            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};