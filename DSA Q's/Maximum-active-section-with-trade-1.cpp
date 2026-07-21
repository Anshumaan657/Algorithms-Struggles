class Solution {
    public:
        int maxActiveSectionsAfterTrade(string s) {
            int originalOnes = 0;
    
            for (char ch : s) {
                if (ch == '1') {
                    originalOnes++;
                }
            }
    
            string t = "1" + s + "1";
    
            vector<pair<char, int>> groups;
    
            int i = 0;
    
            while (i < t.size()) {
                char ch = t[i];
                int count = 0;
    
                while (i < t.size() && t[i] == ch) {
                    count++;
                    i++;
                }
    
                groups.push_back({ch, count});
            }
    
            int bestGain = 0;
    
            for (int i = 1; i < groups.size() - 1; i++) {
                char leftChar = groups[i - 1].first;
                char middleChar = groups[i].first;
                char rightChar = groups[i + 1].first;
    
                if (leftChar == '0' && middleChar == '1' && rightChar == '0') {
                    int gain = groups[i - 1].second + groups[i + 1].second;
                    bestGain = max(bestGain, gain);
                }
            }
    
            return bestGain + originalOnes;
        }
    };