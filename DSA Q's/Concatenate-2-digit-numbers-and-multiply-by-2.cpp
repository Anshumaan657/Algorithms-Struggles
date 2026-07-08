class Solution {
    public:
        vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
            long long MOD = 1000000007;
            int n = s.size();
    
            vector<int> cnt(n + 1, 0);
            vector<int> digits;
    
            for (int i = 0; i < n; i++) {
                cnt[i + 1] = cnt[i];
    
                if (s[i] != '0') {
                    digits.push_back(s[i] - '0');
                    cnt[i + 1]++;
                }
            }
    
            int k = digits.size();
    
            vector<long long> value(k + 1, 0);
            vector<long long> sum(k + 1, 0);
            vector<long long> power(k + 1, 1);
    
            for (int i = 1; i <= k; i++) {
                power[i] = (power[i - 1] * 10) % MOD;
            }
    
            for (int i = 1; i <= k; i++) {
                value[i] = (value[i - 1] * 10 + digits[i - 1]) % MOD;
                sum[i] = sum[i - 1] + digits[i - 1];
            }
    
            vector<int> ans;
    
            for (auto q : queries) {
                int l = q[0];
                int r = q[1];
    
                int left = cnt[l];
                int right = cnt[r + 1];
    
                if (left == right) {
                    ans.push_back(0);
                    continue;
                }
    
                int len = right - left;
    
                long long x = value[right] - (value[left] * power[len]) % MOD;
                x = (x + MOD) % MOD;
    
                long long digitSum = sum[right] - sum[left];
    
                ans.push_back((x * digitSum) % MOD);
            }
    
            return ans;
        }
    };