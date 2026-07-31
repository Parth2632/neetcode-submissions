class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int res = 0;
        int leftmax = 0;
        int rightmax = 0;
        while(left<right){
            if(height[left]<height[right]){
                leftmax = max(height[left],leftmax);
                res += leftmax - height[left];
                left++;
            }
            else{
                rightmax = max(height[right],rightmax);
                res += rightmax - height[right];
                right--;
            }
        }
        return res;
    }
};
