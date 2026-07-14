class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            vector<int> answer;
    
            for (int len = 2; len <= 9; len++) {
                for (int start = 1; start <= 10 - len; start++) {
                    int num = 0;
    
                    for (int digit = start; digit < start + len; digit++) {
                        num = num * 10 + digit;
                    }
    
                    if (num >= low && num <= high) {
                        answer.push_back(num);
                    }
                }
            }
    
            return answer;
        }
    };