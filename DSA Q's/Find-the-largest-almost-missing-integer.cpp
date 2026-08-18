class Solution {
    public:
        int largestInteger(vector<int>& nums, int k) {
            int n = nums.size();
    
            // subarrayCount[x] = number of size-k subarrays
            // in which x appears.
            vector<int> subarrayCount(51, 0);
    
            // Try every subarray of size k.
            for (int start = 0; start <= n - k; start++) {
                // Prevent counting the same number twice
                // inside one subarray.
                vector<bool> appeared(51, false);
    
                for (int i = start; i < start + k; i++) {
                    appeared[nums[i]] = true;
                }
    
                for (int value = 0; value <= 50; value++) {
                    if (appeared[value]) {
                        subarrayCount[value]++;
                    }
                }
            }
    
            // Search from largest value to smallest.
            for (int value = 50; value >= 0; value--) {
                if (subarrayCount[value] == 1) {
                    return value;
                }
            }
    
            return -1;
        }
    };