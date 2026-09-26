class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();
        
        long long expected = n * (n + 1) / 2;
        long long sum = 0;

        for (int x : nums) {
            sum += x;
        }

        return expected - sum;
    }
};