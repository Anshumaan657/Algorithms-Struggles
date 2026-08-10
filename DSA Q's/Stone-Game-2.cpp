class Solution {
    public:
        int solve(int index, int M, vector<int>& piles, vector<int>& suffixSum, vector<vector<int>>& dp) {
            int n = piles.size();
    
            if (index >= n) {
                return 0;
            }
    
            if (index + 2 * M >= n) {
                return suffixSum[index];
            }
    
            if (dp[index][M] != -1) {
                return dp[index][M];
            }
    
            int best = 0;
    
            for (int X = 1; X <= 2 * M; X++) {
                int newM = max(M, X);
    
                int opponentStones = solve(index + X, newM, piles, suffixSum, dp);
    
                int myStones = suffixSum[index] - opponentStones;
    
                best = max(best, myStones);
            }
    
            dp[index][M] = best;
            return best;
        }
    
        int stoneGameII(vector<int>& piles) {
            int n = piles.size();
    
            vector<int> suffixSum(n + 1, 0);
    
            for (int i = n - 1; i >= 0; i--) {
                suffixSum[i] = piles[i] + suffixSum[i + 1];
            }
    
            vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    
            return solve(0, 1, piles, suffixSum, dp);
        }
    };