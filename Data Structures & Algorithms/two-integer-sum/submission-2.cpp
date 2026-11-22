class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0 ;i < n ;i++){
            int com = target - nums[i];
            if(mp.find(com) != mp.end()){
                return {mp[com],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
