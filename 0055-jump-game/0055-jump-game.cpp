class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > maxreach){
                return false;
            }
            maxreach = max(nums[i] + i, maxreach);
        }
        return true;
    }
};