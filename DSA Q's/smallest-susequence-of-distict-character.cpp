class Solution {
    public:
        string smallestSubsequence(string s) {
            vector<int> last(26, 0);
            vector<bool> used(26, false);
    
            
            for (int i = 0; i < s.size(); i++) {
                last[s[i] - 'a'] = i;
            }
    
            string answer = "";
    
            for (int i = 0; i < s.size(); i++) {
                char ch = s[i];
                if (used[ch - 'a'] == true) {
                    continue;
                }
                while (!answer.empty() &&
                       answer.back() > ch &&
                       last[answer.back() - 'a'] > i) {
                    
                    used[answer.back() - 'a'] = false;
                    answer.pop_back();
                }
    
                answer.push_back(ch);
                used[ch - 'a'] = true;
            }
    
            return answer;
        }
    }; 