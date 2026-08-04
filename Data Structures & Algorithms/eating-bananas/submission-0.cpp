class Solution {
public:

    // Checks if eating with speed k is possible within h hours
    bool valid(vector<int>& piles, int h, int k) {
        int hr = 0;

        for(int i = 0; i < piles.size(); i++) {

            // Calculate hours needed for this pile
            if(piles[i] % k == 0) {
                hr += piles[i] / k;
            }
            else {
                hr += piles[i] / k + 1;
            }

            // No need to continue if already impossible
            if(hr > h) {
                return false;
            }
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int high = INT_MIN;

        // Maximum possible speed = largest pile
        for(int i = 0; i < piles.size(); i++) {
            high = max(piles[i], high);
        }

        // MISTAKE 1:
        // You used low = 0
        // Speed cannot be 0 because we do piles[i] % k and piles[i]/k
        // Division by zero error
        int low = 1;


        // MISTAKE 2:
        // ans was declared but not initialized
        // Initialize it with a valid value
        int ans = high;


        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(valid(piles, h, mid)) {

                // This speed works, store answer
                ans = mid;

                // Try finding a smaller speed
                high = mid - 1;
            }
            else {

                // Speed is too slow, increase it
                low = mid + 1;
            }
        }

        return ans;
    }
};
