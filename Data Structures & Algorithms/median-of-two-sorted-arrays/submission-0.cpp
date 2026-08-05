class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        int total_length = m+n;

        while(low<=high){

            int partition1 = low + (high-low)/2;
            int partition2 = (total_length+1)/2 - partition1;

            int l1 = (partition1==0) ? INT_MIN : nums1[partition1-1];
            int r1 = (partition1==m) ? INT_MAX : nums1[partition1];

            int l2 = (partition2==0) ? INT_MIN : nums2[partition2-1];
            int r2 = (partition2==n) ? INT_MAX : nums2[partition2];


            if(l1<=r2 && l2<=r1){

                if(total_length%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else{
                    return max(l1,l2);
                }

            }
            else if(l1>r2){
                high = partition1-1;
            }
            else{
                low = partition1+1;
            }
        }

        return 0;
    }
};
