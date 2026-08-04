class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size()-1;
        int ans = high;
        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid]<=nums[high]){ //minimum in left half or at mid
                high = mid;
            }
            else{ // minimum in right half
                low = mid+1;
            }
        }
        return nums[high];
    }
};
