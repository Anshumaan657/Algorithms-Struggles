class Solution {
    public:
        int minimumPushes(string word) {
            vector<int> freq(26, 0);
    
            for (char ch : word) {
                freq[ch - 'a']++;
            }
    
            sort(freq.begin(), freq.end(), greater<int>());
    
            int answer = 0;
    
            for (int i = 0; i < 26; i++) {
                if (freq[i] == 0) {
                    continue;
                }
    
                int pushCount = (i / 8) + 1;
    
                answer += freq[i] * pushCount;
            }
    
            return answer;
        }
    };