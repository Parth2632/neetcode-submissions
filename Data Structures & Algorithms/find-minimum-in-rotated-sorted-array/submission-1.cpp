class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size()-1;
        int ans = high;
        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid]<=nums[high]){ //sorted part 
                high = mid;
            }
            else{ //unsorted part
                low = mid+1;
            }
        }
        return nums[high];
    }
};
