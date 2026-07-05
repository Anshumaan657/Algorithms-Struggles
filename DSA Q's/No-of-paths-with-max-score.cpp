class Solution {
    public:
        vector<int> pathsWithMaxScore(vector<string>& board) {
            int n = board.size();
            int mod = 1000000007;
    
            vector<vector<int>> score(n, vector<int>(n, -1));
            vector<vector<int>> ways(n, vector<int>(n, 0));
    
            score[n - 1][n - 1] = 0;
            ways[n - 1][n - 1] = 1;
    
            for (int i = n - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] == 'X') continue;
                    if (i == n - 1 && j == n - 1) continue;
    
                    int value = 0;
    
                    if (board[i][j] >= '1' && board[i][j] <= '9') {
                        value = board[i][j] - '0';
                    }
    
                    vector<pair<int, int>> previousCells = {
                        {i + 1, j},
                        {i, j + 1},
                        {i + 1, j + 1}
                    };
    
                    for (auto cell : previousCells) {
                        int prevI = cell.first;
                        int prevJ = cell.second;
    
                        if (prevI >= n || prevJ >= n) continue;
                        if (score[prevI][prevJ] == -1) continue;
    
                        int candidateScore = score[prevI][prevJ] + value;
    
                        if (candidateScore > score[i][j]) {
                            score[i][j] = candidateScore;
                            ways[i][j] = ways[prevI][prevJ];
                        } 
                        else if (candidateScore == score[i][j]) {
                            ways[i][j] += ways[prevI][prevJ];
                            ways[i][j] %= mod;
                        }
                    }
                }
            }
    
            if (score[0][0] == -1) {
                return {0, 0};
            }
    
            return {score[0][0], ways[0][0]};
        }
    };