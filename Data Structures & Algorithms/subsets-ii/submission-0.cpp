class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(nums.begin(), nums.end());

        function<void(int)> backtrack = [&](int start) {
            ans.push_back(curr);

            for (int i = start; i < nums.size(); i++) {
                // Skip duplicates at the same level
                if (i > start && nums[i] == nums[i - 1])
                    continue;

                curr.push_back(nums[i]);
                backtrack(i + 1);
                curr.pop_back();
            }
        };

        backtrack(0);
        return ans;
    }
};