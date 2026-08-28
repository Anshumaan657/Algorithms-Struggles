class Solution {
    public:
        string shortestBeautifulSubstring(string s, int k) {
            int n = s.size();
            int minimumLength = n + 1;
            string answer = "";
    
            for (int i = 0; i < n; i++) {
                int ones = 0;
    
                for (int j = i; j < n; j++) {
                    if (s[j] == '1') {
                        ones++;
                    }
    
                    if (ones == k) {
                        int length = j - i + 1;
                        string current = s.substr(i, length);
    
                        if (length < minimumLength) {
                            minimumLength = length;
                            answer = current;
                        }
                        else if (length == minimumLength && current < answer) {
                            answer = current;
                        }
                    }
    
                    if (ones > k) {
                        break;
                    }
                }
            }
    
            return answer;
        }
    };