class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int leftsum = 0;
        for(int x : nums){
            total += x;
        }
        for(int i=0;i<n;i++){
            int rightsum = total - leftsum - nums[i];
            if(rightsum == leftsum){
                return i;
            }
            leftsum += nums[i];
        }
        return -1;
    }
};