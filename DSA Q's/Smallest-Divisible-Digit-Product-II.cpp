class Solution {
    public:
        vector<vector<int>> digitFactor = {
            {0, 0}, // 0 not used
            {0, 0}, // 1
            {1, 0}, // 2
            {0, 1}, // 3
            {2, 0}, // 4
            {0, 0}, // 5 handled separately
            {1, 1}, // 6
            {0, 0}, // 7 handled separately
            {3, 0}, // 8
            {0, 2}  // 9
        };
    
        vector<int> f2, f3, f5, f7;
        vector<vector<int>> dp;
    
        int minDigitsFor23(int two, int three) {
            return dp[two][three];
        }
    
        int minDigits(vector<int> need) {
            return need[2] + need[3] + minDigitsFor23(need[0], need[1]);
        }
    
        vector<int> removeDigit(vector<int> need, int digit) {
            if (digit == 2) need[0] = max(0, need[0] - 1);
            if (digit == 3) need[1] = max(0, need[1] - 1);
            if (digit == 4) need[0] = max(0, need[0] - 2);
            if (digit == 5) need[2] = max(0, need[2] - 1);
            if (digit == 6) {
                need[0] = max(0, need[0] - 1);
                need[1] = max(0, need[1] - 1);
            }
            if (digit == 7) need[3] = max(0, need[3] - 1);
            if (digit == 8) need[0] = max(0, need[0] - 3);
            if (digit == 9) need[1] = max(0, need[1] - 2);
    
            return need;
        }
    
        string buildSmallest(int length, vector<int> need) {
            string ans = "";
    
            for (int pos = 0; pos < length; pos++) {
                for (int digit = 1; digit <= 9; digit++) {
                    vector<int> newNeed = removeDigit(need, digit);
    
                    int remaining = length - pos - 1;
    
                    if (minDigits(newNeed) <= remaining) {
                        ans += char('0' + digit);
                        need = newNeed;
                        break;
                    }
                }
            }
    
            return ans;
        }
    
        string smallestNumber(string num, long long t) {
            vector<int> need(4, 0); 
            // need[0] = power of 2
            // need[1] = power of 3
            // need[2] = power of 5
            // need[3] = power of 7
    
            while (t % 2 == 0) {
                need[0]++;
                t /= 2;
            }
    
            while (t % 3 == 0) {
                need[1]++;
                t /= 3;
            }
    
            while (t % 5 == 0) {
                need[2]++;
                t /= 5;
            }
    
            while (t % 7 == 0) {
                need[3]++;
                t /= 7;
            }
    
            if (t != 1) {
                return "-1";
            }
    
            int maxTwo = need[0];
            int maxThree = need[1];
    
            dp.assign(maxTwo + 1, vector<int>(maxThree + 1, 1000000));
            dp[0][0] = 0;
    
            vector<pair<int, int>> options = {
                {1, 0}, // 2
                {0, 1}, // 3
                {2, 0}, // 4
                {1, 1}, // 6
                {3, 0}, // 8
                {0, 2}  // 9
            };
    
            for (int a = 0; a <= maxTwo; a++) {
                for (int b = 0; b <= maxThree; b++) {
                    for (auto op : options) {
                        int na = min(maxTwo, a + op.first);
                        int nb = min(maxThree, b + op.second);
    
                        dp[na][nb] = min(dp[na][nb], dp[a][b] + 1);
                    }
                }
            }
    
            int n = num.size();
    
            vector<vector<int>> prefix(n + 1, vector<int>(4, 0));
            vector<bool> validPrefix(n + 1, true);
    
            for (int i = 0; i < n; i++) {
                prefix[i + 1] = prefix[i];
                validPrefix[i + 1] = validPrefix[i];
    
                if (num[i] == '0') {
                    validPrefix[i + 1] = false;
                } else {
                    prefix[i + 1] = removeDigit(prefix[i + 1], -1);
    
                    int digit = num[i] - '0';
                    vector<int> dummy(4, 0);
    
                    if (digit == 2) prefix[i + 1][0]++;
                    if (digit == 3) prefix[i + 1][1]++;
                    if (digit == 4) prefix[i + 1][0] += 2;
                    if (digit == 5) prefix[i + 1][2]++;
                    if (digit == 6) {
                        prefix[i + 1][0]++;
                        prefix[i + 1][1]++;
                    }
                    if (digit == 7) prefix[i + 1][3]++;
                    if (digit == 8) prefix[i + 1][0] += 3;
                    if (digit == 9) prefix[i + 1][1] += 2;
                }
            }
    
            if (validPrefix[n]) {
                vector<int> remaining = need;
    
                for (int i = 0; i < 4; i++) {
                    remaining[i] = max(0, remaining[i] - prefix[n][i]);
                }
    
                if (minDigits(remaining) == 0) {
                    return num;
                }
            }
    
            for (int pos = n - 1; pos >= 0; pos--) {
                if (!validPrefix[pos]) {
                    continue;
                }
    
                int startDigit;
    
                if (num[pos] == '0') {
                    startDigit = 1;
                } else {
                    startDigit = (num[pos] - '0') + 1;
                }
    
                for (int digit = startDigit; digit <= 9; digit++) {
                    vector<int> remaining = need;
    
                    for (int i = 0; i < 4; i++) {
                        remaining[i] = max(0, remaining[i] - prefix[pos][i]);
                    }
    
                    remaining = removeDigit(remaining, digit);
    
                    int slotsLeft = n - pos - 1;
    
                    if (minDigits(remaining) <= slotsLeft) {
                        string ans = num.substr(0, pos);
                        ans += char('0' + digit);
                        ans += buildSmallest(slotsLeft, remaining);
    
                        return ans;
                    }
                }
            }
    
            int length = max(n + 1, minDigits(need));
    
            return buildSmallest(length, need);
        }
    };