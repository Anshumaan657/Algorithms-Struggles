class Solution {
    public:
        vector<long long> prefixSum;
        vector<vector<int>> dp;
    
        // Returns the maximum score Alice can get
        // from stoneValue[left...right].
        int solve(int left, int right, vector<int>& stoneValue) {
            // Only one stone remains, so we cannot divide it.
            if (left == right) {
                return 0;
            }
    
            if (dp[left][right] != -1) {
                return dp[left][right];
            }
    
            int bestScore = 0;
    
            // Divide after index split.
            for (int split = left; split < right; split++) {
                long long leftSum =
                    prefixSum[split + 1] - prefixSum[left];
    
                long long rightSum =
                    prefixSum[right + 1] - prefixSum[split + 1];
    
                if (leftSum < rightSum) {
                    // Bob removes the right part.
                    int currentScore =
                        leftSum + solve(left, split, stoneValue);
    
                    bestScore = max(bestScore, currentScore);
                }
                else if (rightSum < leftSum) {
                    // Bob removes the left part.
                    int currentScore =
                        rightSum + solve(split + 1, right, stoneValue);
    
                    bestScore = max(bestScore, currentScore);
                }
                else {
                    // Both sums are equal, so Alice chooses.
                    int continueWithLeft =
                        leftSum + solve(left, split, stoneValue);
    
                    int continueWithRight =
                        rightSum + solve(split + 1, right, stoneValue);
    
                    bestScore = max(
                        bestScore,
                        max(continueWithLeft, continueWithRight)
                    );
                }
            }
    
            dp[left][right] = bestScore;
            return bestScore;
        }
    
        int stoneGameV(vector<int>& stoneValue) {
            int n = stoneValue.size();
    
            // prefixSum[i] stores the sum before index i.
            prefixSum.resize(n + 1, 0);
    
            for (int i = 0; i < n; i++) {
                prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
            }
    
            dp.assign(n, vector<int>(n, -1));
    
            return solve(0, n - 1, stoneValue);
        }
    };