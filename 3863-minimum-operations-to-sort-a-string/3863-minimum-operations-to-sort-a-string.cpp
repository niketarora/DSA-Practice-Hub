class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        bool sorted = true;
        char mx = s[0], mn = s[0];

        for (int i = 0; i < n; i++) {
            if (s[i] > mx) mx = s[i];
            if (s[i] < mn) mn = s[i];
            if (i > 0 && s[i - 1] > s[i]) sorted = false;
        }

        if (sorted) return 0;
        if (n == 2) return -1;
        if (s[0] == mn || s[n - 1] == mx) return 1;

        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) return 2;
        }

        return 3;
    }
};