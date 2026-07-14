class solution{
    public: 
    solve(int start, vector<int>& nums,vector<int>&  current, vector<vector<int>>& answer){
        answer.push_back(current);
        for(int i = start; i < num.size(); i++){
            if(i > start && nums[i] == nums[i-1])
                continue;
        }
        current.push_back(nums[i])
        solve( i+1, nums, current, answer);
        current.pop_back();
        vector<vector<int>> subsetsWithDup(vector<int>& nums){
            sort(nums.begin(), nums.end());
            vector<vector<int>> answer;
            vector<int> current;
            solve(0, nums, current, answer);
            return answer;
        }
    };
}