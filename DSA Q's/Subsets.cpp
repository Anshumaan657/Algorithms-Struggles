class Solution {
    public:
        void solve(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& answer) {
            if (index == nums.size()) {
                answer.push_back(current);
                return;
            }
    
            
            solve(nums, index + 1, current, answer);
    
            
            current.push_back(nums[index]);
            solve(nums, index + 1, current, answer);
    
            
            current.pop_back();
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> answer;
            vector<int> current;
    
            solve(nums, 0, current, answer);
    
            return answer;
        }
    };