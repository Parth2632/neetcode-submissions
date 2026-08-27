class Solution {
public:

    int solve(vector<int>& nums, int start, int end, vector<int>& dp){

        for(int i=end; i>=start; i--){

            int take = nums[i] + dp[i+2];

            int skip = dp[i+1];

            dp[i] = max(take, skip);
        }

        return dp[start];
    }


    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];


        vector<int> dp1(n+2,0);
        vector<int> dp2(n+2,0);


        int num1 = solve(nums,0,n-2,dp1);

        int num2 = solve(nums,1,n-1,dp2);


        return max(num1,num2);
    }
};
