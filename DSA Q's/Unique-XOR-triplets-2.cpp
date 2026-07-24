class Solution {
    public:
        int uniqueXorTriplets(vector<int>& nums) {
            unordered_set<int> pairXor;
            unordered_set<int> tripletXor;
    
            int n = nums.size();
    
            // Step 1: store all possible nums[i] ^ nums[j]
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int value = nums[i] ^ nums[j];
                    pairXor.insert(value);
                }
            }
    
            // Step 2: use every pair XOR with every nums[k]
            for (int value : pairXor) {
                for (int k = 0; k < n; k++) {
                    int finalValue = value ^ nums[k];
                    tripletXor.insert(finalValue);
                }
            }
    
            return tripletXor.size();
        }
    };