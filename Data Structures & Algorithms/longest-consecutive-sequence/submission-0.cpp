class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int longest = 0;

        for (int x : seen) {

            if (seen.find(x - 1) == seen.end()) {
                int current = x;
                int length = 1;

                while (seen.find(current + 1) != seen.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};