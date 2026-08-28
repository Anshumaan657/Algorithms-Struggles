class Solution {
    public:
        string makeLargestPalindrome(
            string left,
            vector<int>& remaining,
            string middle
        ) {
            for (int i = 25; i >= 0; i--) {
                while (remaining[i] > 0) {
                    left.push_back('a' + i);
                    remaining[i]--;
                }
            }
    
            string right = left;
            reverse(right.begin(), right.end());
    
            return left + middle + right;
        }
    
        string lexPalindromicPermutation(string s, string target) {
            vector<int> frequency(26, 0);
    
            for (char ch : s) {
                frequency[ch - 'a']++;
            }
    
            int oddCount = 0;
            string middle = "";
    
            for (int i = 0; i < 26; i++) {
                if (frequency[i] % 2 == 1) {
                    oddCount++;
                    middle.push_back('a' + i);
                }
            }
    
            if (oddCount > 1) {
                return "";
            }
    
            vector<int> remaining(26, 0);
    
            for (int i = 0; i < 26; i++) {
                remaining[i] = frequency[i] / 2;
            }
    
            int halfLength = s.size() / 2;
            string left = "";
    
            for (int position = 0; position < halfLength; position++) {
                bool found = false;
    
                for (int letter = 0; letter < 26; letter++) {
                    if (remaining[letter] == 0) {
                        continue;
                    }
    
                    left.push_back('a' + letter);
                    remaining[letter]--;
    
                    vector<int> copy = remaining;
    
                    string largestPossible =
                        makeLargestPalindrome(left, copy, middle);
    
                    if (largestPossible > target) {
                        found = true;
                        break;
                    }
    
                    left.pop_back();
                    remaining[letter]++;
                }
    
                if (!found) {
                    return "";
                }
            }
    
            string right = left;
            reverse(right.begin(), right.end());
    
            string answer = left + middle + right;
    
            if (answer > target) {
                return answer;
            }
    
            return "";
        }
    };