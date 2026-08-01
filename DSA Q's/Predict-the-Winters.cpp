class Solution {
    public:
        int solve(int left, int right, vector<int>& nums) {
            if (left == right) {
                return nums[left];
            }
    
            int chooseLeft = nums[left] - solve(left + 1, right, nums);
            int chooseRight = nums[right] - solve(left, right - 1, nums);
    
            return max(chooseLeft, chooseRight);
        }
    
        bool predictTheWinner(vector<int>& nums) {
            int n = nums.size();
    
            int difference = solve(0, n - 1, nums);
    
            return difference >= 0;
        }
    };