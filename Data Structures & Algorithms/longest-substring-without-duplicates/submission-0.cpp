class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);

        int left = 0;
        int right = 0;
        int ans = 0;

        while (right < s.size()) {

            freq[s[right]]++;

            // Duplicate found
            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};