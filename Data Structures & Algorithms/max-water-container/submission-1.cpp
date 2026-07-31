class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int res = 0;
        while(left<right){
            int area = (right-left) * min(heights[left],heights[right]);
            res = max(res,area);
            if(heights[left]<heights[right]){
                left++; //always move the shorter wall 
            }
            else{
                right--;
            }
        }
        return res;
    }
};
