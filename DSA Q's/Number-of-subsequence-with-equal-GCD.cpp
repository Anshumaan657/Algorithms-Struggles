class Solution {
    public:
        int subsequencePairCount(vector<int>& nums) {
            int mod = 1000000007;
    
            vector<vector<long long>> dp(201, vector<long long>(201, 0));
    
            dp[0][0] = 1;
    
            for (int x : nums) {
                vector<vector<long long>> newDp(201, vector<long long>(201, 0));
    
                for (int g1 = 0; g1 <= 200; g1++) {
                    for (int g2 = 0; g2 <= 200; g2++) {
                        if (dp[g1][g2] == 0) {
                            continue;
                        }
    
                        long long count = dp[g1][g2];
    
                        // choice 1: skip x
                        newDp[g1][g2] = (newDp[g1][g2] + count) % mod;
    
                        // choice 2: put x in seq1
                        int newG1 = __gcd(g1, x);
                        newDp[newG1][g2] = (newDp[newG1][g2] + count) % mod;
    
                        // choice 3: put x in seq2
                        int newG2 = __gcd(g2, x);
                        newDp[g1][newG2] = (newDp[g1][newG2] + count) % mod;
                    }
                }
    
                dp = newDp;
            }
    
            long long answer = 0;
            for(int g =1; g<=200; g++){
                answer = (answer + dp[g][g]) % mod;
            }
            return answer;
        }
    };