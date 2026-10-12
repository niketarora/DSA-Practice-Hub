#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        // Convert to set for O(1) lookups and to handle duplicates automatically
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            // Check if 'num' is the start of a sequence
            // If num - 1 exists, 'num' is not the start; skip it to avoid O(n^2)
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Count consecutive numbers starting from 'currentNum'
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = std::max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
