class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0;

        for (int x : nums) {
            if (x != val) {
                nums[write] = x;
                write++;
            }
        }

        return write;
    }
};