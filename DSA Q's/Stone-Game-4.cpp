class Solution {
    public:
        bool winnerSquareGame(int n) {
            vector<bool> dp(n + 1, false);
    
            for (int stones = 1; stones <= n; stones++) {
                for (int x = 1; x * x <= stones; x++) {
                    int square = x * x;
    
                    if (dp[stones - square] == false) {
                        dp[stones] = true;
                        break;
                    }
                }
            }
    
            return dp[n];
        }
    };