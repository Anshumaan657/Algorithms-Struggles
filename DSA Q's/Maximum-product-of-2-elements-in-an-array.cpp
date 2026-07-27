class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            sort(nums.begin(), nums.end());
    
            int n = nums.size();
    
            int largest = nums[n - 1];
            int secondLargest = nums[n - 2];
    
            return (largest - 1) * (secondLargest - 1);
        }
    };