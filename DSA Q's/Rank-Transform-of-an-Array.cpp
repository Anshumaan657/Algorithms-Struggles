class Solution {
    public:
        vector<int> arrayRankTransform(vector<int>& arr) {
            vector<int> sorted = arr;
    
            sort(sorted.begin(), sorted.end());
    
            unordered_map<int, int> rank;
            int currentRank = 1;
    
            for (int i = 0; i < sorted.size(); i++) {
                int number = sorted[i];
    
                if (rank.find(number) == rank.end()) {
                    rank[number] = currentRank;
                    currentRank++;
                }
            }
    
            vector<int> answer;
    
            for (int i = 0; i < arr.size(); i++) {
                int number = arr[i];
                answer.push_back(rank[number]);
            }
    
            return answer;
        }
    };