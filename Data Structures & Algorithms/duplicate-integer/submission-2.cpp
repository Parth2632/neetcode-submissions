class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>f;
        for(int i=0; i<nums.size(); i++){
            if(f.find(nums[i])!=f.end()){
                return true;
            }
            f[nums[i]]++;
        }
        return false;
    }
};