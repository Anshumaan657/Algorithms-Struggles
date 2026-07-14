class Solution {
    public:
        void solve(int index, vector<int>& candidates, int target,
                   vector<int>& current, vector<vector<int>>& answer) {
            
            if (target == 0) {
                answer.push_back(current);
                return;
            }
    
            if (target < 0) {
                return;
            }
    
            for (int i = index; i < candidates.size(); i++) {
                current.push_back(candidates[i]);
    
                solve(i, candidates, target - candidates[i], current, answer);
    
                current.pop_back();
            }
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> answer;
            vector<int> current;
    
            solve(0, candidates, target, current, answer);
    
            return answer;
        }
    };