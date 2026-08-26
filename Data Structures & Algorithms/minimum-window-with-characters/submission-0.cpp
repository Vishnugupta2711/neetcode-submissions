class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> need(128, 0);

        for (char c : t) {
            need[c]++;
        }

        vector<int> window(128, 0);

        int needCount = 0;

        for (int i = 0; i < 128; i++) {
            if (need[i] > 0) {
                needCount++;
            }
        }

        int have = 0;

        int left = 0;

        int bestStart = 0;
        int bestLength = INT_MAX;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];
            window[c]++;

            if (need[c] > 0 && window[c] == need[c]) {
                have++;
            }

            while (have == needCount) {

                int currentLength = right - left + 1;

                if (currentLength < bestLength) {
                    bestLength = currentLength;
                    bestStart = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need[leftChar] > 0 &&
                    window[leftChar] < need[leftChar]) {
                    have--;
                }

                left++;
            }
        }

        if (bestLength == INT_MAX) {
            return "";
        }

        return s.substr(bestStart, bestLength);
    }
};