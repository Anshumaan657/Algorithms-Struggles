class Solution {
    public:
        long long LIMIT = 1000001;
    
        long long combination(int n, int r) {
            r = min(r, n - r);
    
            long long ans = 1;
    
            for (int i = 1; i <= r; i++) {
                ans = ans * (n - r + i) / i;
    
                if (ans >= LIMIT) {
                    return LIMIT;
                }
            }
    
            return ans;
        }
    
        long long countWays(vector<int>& count) {
            int total = 0;
    
            for (int x : count) {
                total += x;
            }
    
            long long ways = 1;
    
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) {
                    long long choose = combination(total, count[i]);
    
                    ways = ways * choose;
    
                    if (ways >= LIMIT) {
                        return LIMIT;
                    }
    
                    total -= count[i];
                }
            }
    
            return ways;
        }
    
        string smallestPalindrome(string s, int k) {
            vector<int> freq(26, 0);
    
            for (char ch : s) {
                freq[ch - 'a']++;
            }
    
            vector<int> halfCount(26, 0);
            char middle = '#';
    
            for (int i = 0; i < 26; i++) {
                halfCount[i] = freq[i] / 2;
    
                if (freq[i] % 2 == 1) {
                    middle = char('a' + i);
                }
            }
    
            if (countWays(halfCount) < k) {
                return "";
            }
    
            string left = "";
            int halfLength = s.size() / 2;
    
            for (int pos = 0; pos < halfLength; pos++) {
                for (int i = 0; i < 26; i++) {
                    if (halfCount[i] == 0) {
                        continue;
                    }
    
                    halfCount[i]--;
    
                    long long ways = countWays(halfCount);
    
                    if (ways >= k) {
                        left += char('a' + i);
                        break;
                    } else {
                        k -= ways;
                        halfCount[i]++;
                    }
                }
            }
    
            string right = left;
            reverse(right.begin(), right.end());
    
            if (middle == '#') {
                return left + right;
            }
    
            return left + middle + right;
        }
    };