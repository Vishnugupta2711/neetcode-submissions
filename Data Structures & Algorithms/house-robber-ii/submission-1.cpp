class Solution {
public:

    // Solve normal House Robber for range [start, end]
    int solve(vector<int>& nums, int start, int end) {

        int prev2 = 0;  
        int prev1 = 0; 

        for(int i = start; i <= end; i++) {


            int curr = max(nums[i] + prev2, prev1);


            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        int firstCase = solve(nums, 0, n - 2);

        int secondCase = solve(nums, 1, n - 1);

        return max(firstCase, secondCase);
    }
};