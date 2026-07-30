class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>f;
        for(int i=0; i<nums.size();i++){
            int need = target - nums[i];
            if(f.find(need)!=f.end()){
                return{f[need],i};
            }
            f[nums[i]] = i;
        }
        return {};
    }
};
