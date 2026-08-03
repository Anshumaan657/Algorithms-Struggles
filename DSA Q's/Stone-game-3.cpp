class Solution {
    public:
        string stoneGameIII(vector<int>& stoneValue) {
            int n = stoneValue.size();
    
            vector<int> dp(n + 1, 0);
    
            for (int i = n - 1; i >= 0; i--) {
                int take = 0;
                dp[i] = -1000000000;
    
                for (int x = 0; x < 3; x++) {
                    if (i + x >= n) {
                        break;
                    }
    
                    take += stoneValue[i + x];
    
                    dp[i] = max(dp[i], take - dp[i + x + 1]);
                }
            }
    
            if (dp[0] > 0) {
                return "Alice";
            }
            else if (dp[0] < 0) {
                return "Bob";
            }
    
            return "Tie";
        }
    };