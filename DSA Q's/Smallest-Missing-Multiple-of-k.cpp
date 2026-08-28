class Solution {
    public:
        int missingMultiple(vector<int>& nums, int k) {
            unordered_set<int> present;
                    
            for (int number : nums) {
                present.insert(number);
            }        
            int multiple = k;
    
            
            while (present.count(multiple)) {
                multiple += k;
            }
    
            return multiple;
        }
    };