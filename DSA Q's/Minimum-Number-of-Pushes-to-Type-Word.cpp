class Solution {
    public:
        int minimumPushes(string word) {
            int answer = 0;
    
            for (int i = 0; i < word.size(); i++) {
                int pushCount = (i / 8) + 1;
                answer += pushCount;
            }
    
            return answer;
        }
    };