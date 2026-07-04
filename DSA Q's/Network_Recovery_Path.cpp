class Solution {
    public:
        int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
            int n = online.size();
    
            vector<vector<pair<int, int>>> graph(n);
            vector<int> indegree(n, 0);
    
            int maxCost = 0;
    
            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int cost = e[2];
    
                graph[u].push_back({v, cost});
                indegree[v]++;
                maxCost = max(maxCost, cost);
            }
    
            // Topological order
            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (indegree[i] == 0) q.push(i);
            }
    
            vector<int> topo;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
    
                topo.push_back(node);
    
                for (auto &[next, cost] : graph[node]) {
                    indegree[next]--;
                    if (indegree[next] == 0) q.push(next);
                }
            }
    
            auto can = [&](int score) {
                const long long INF = 4e18;
                vector<long long> dist(n, INF);
    
                dist[0] = 0;
    
                for (int node : topo) {
                    if (dist[node] == INF) continue;
                    if (!online[node]) continue;
    
                    for (auto &[next, cost] : graph[node]) {
                        if (!online[next]) continue;
                        if (cost < score) continue;
    
                        dist[next] = min(dist[next], dist[node] + cost);
                    }
                }
    
                return dist[n - 1] <= k;
            };
    
            int low = 0;
            int high = maxCost;
            int answer = -1;
    
            while (low <= high) {
                int mid = low + (high - low) / 2;
    
                if (can(mid)) {
                    answer = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
    
            return answer;
        }
    };