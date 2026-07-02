class Solution {
    public:
        int maximumSafenessFactor(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<vector<int>> dist(n, vector<int>(n, -1));
            queue<pair<int,int>> q;
    
            // Arrange all the thieves in queue
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        dist[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }
    
            vector<int> dr = {-1, 1, 0, 0};
            vector<int> dc = {0, 0, -1, 1};
    
            // Multi-source BFS to find nearest thief distance
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
    
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
    
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
    
            auto canReach = [&](int safe) {
                if (dist[0][0] < safe || dist[n-1][n-1] < safe)
                    return false;
    
                vector<vector<int>> visited(n, vector<int>(n, 0));
                queue<pair<int,int>> q;
    
                q.push({0, 0});
                visited[0][0] = 1;
    
                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
    
                    if (r == n - 1 && c == n - 1)
                        return true;
    
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
    
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                            !visited[nr][nc] && dist[nr][nc] >= safe) {
                            visited[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }
    
                return false;
            };
    
            // Binary search maximum safe factor
            int low = 0, high = 2 * n, ans = 0;
    
            while (low <= high) {
                int mid = low + (high - low) / 2;
    
                if (canReach(mid)) {
                    ans = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
    
            return ans;
        }
    };