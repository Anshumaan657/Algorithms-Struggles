class Solution {
    public:
        vector<int> validSequence(string word1, string word2) {
            int n = word1.size();
            int m = word2.size();
    
            vector<int> exact(n + 1, 0);
            vector<int> almost(n + 1, 0);
    
            for (int i = n - 1; i >= 0; i--) {
                exact[i] = exact[i + 1];
    
                if (exact[i + 1] < m &&
                    word1[i] == word2[m - 1 - exact[i + 1]]) {
                    exact[i] = exact[i + 1] + 1;
                }
    
                almost[i] = almost[i + 1];
    
                if (almost[i + 1] < m &&
                    word1[i] == word2[m - 1 - almost[i + 1]]) {
                    almost[i] = max(almost[i], almost[i + 1] + 1);
                }
    
                if (exact[i + 1] < m) {
                    almost[i] = max(almost[i], exact[i + 1] + 1);
                }
            }
    
            vector<int> answer;
    
            int index = 0;
            bool usedChange = false;
    
            for (int pos = 0; pos < m; pos++) {
                bool found = false;
    
                while (index < n) {
                    int remaining = m - pos - 1;
    
                    if (word1[index] == word2[pos]) {
                        if (usedChange == true) {
                            if (exact[index + 1] >= remaining) {
                                answer.push_back(index);
                                index++;
                                found = true;
                                break;
                            }
                        } else {
                            if (almost[index + 1] >= remaining) {
                                answer.push_back(index);
                                index++;
                                found = true;
                                break;
                            }
                        }
                    } else {
                        if (usedChange == false) {
                            if (exact[index + 1] >= remaining) {
                                answer.push_back(index);
                                index++;
                                usedChange = true;
                                found = true;
                                break;
                            }
                        }
                    }
    
                    index++;
                }
    
                if (found == false) {
                    return {};
                }
            }
    
            return answer;
        }
    };