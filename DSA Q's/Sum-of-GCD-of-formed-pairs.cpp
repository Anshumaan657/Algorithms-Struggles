class Solution{
    public:
    long long gcdSum(vector<int>& nums){
        int currentmax = 0;
        vector<int> prefixGcd;
        for(int i = 0; i< nums.size(); i++){
            currentmax = max(currentmax, nums[i]);
            prefixGcd.push_back(gcd(currentmax, nums[i]));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int left = 0;
        int right = prefixGcd.size()-1;
        long long answer = 0;
        while (left<right){
            answer = answer + gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return answer;
    }
};