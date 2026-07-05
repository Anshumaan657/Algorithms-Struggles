class Solution {
    public:
        int minScore(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int, int>>> graph(n + 1);
    
            for (auto &road : roads) {
                int a = road[0];
                int b = road[1];
                int dist = road[2];
    
                graph[a].push_back({b, dist});
                graph[b].push_back({a, dist});
            }
    
            vector<int> visited(n + 1, 0);
            queue<int> q;
    
            q.push(1);
            visited[1] = 1;
    
            int answer = INT_MAX;
    
            while (!q.empty()) {
                int city = q.front();
                q.pop();
    
                for (auto &nextRoad : graph[city]) {
                    int nextCity = nextRoad.first;
                    int distance = nextRoad.second;
    
                    answer = min(answer, distance);
    
                    if (!visited[nextCity]) {
                        visited[nextCity] = 1;
                        q.push(nextCity);
                    }
                }
            }
    
            return answer;
        }
    };