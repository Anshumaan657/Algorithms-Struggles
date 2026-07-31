class Solution {
    public:
        string smallestPalindrome(string s) {
            int count[26] = {0};
    
            for (char ch : s) {
                count[ch - 'a']++;
            }
    
            string left = "";
            string middle = "";
    
            for (int i = 0; i < 26; i++) {
                left += string(count[i] / 2, char('a' + i));
    
                if (count[i] % 2 == 1) {
                    middle = char('a' + i);
                }
            }
    
            string right = left;
            reverse(right.begin(), right.end());
    
            return left + middle + right;
        }
    };