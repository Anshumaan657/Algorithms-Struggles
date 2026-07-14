class Solution {
    public:
        void dfs(int node, vector<vector<int>>& graph, vector<int>& visited, int& nodeCount, int& edgeCount) {
            visited[node] = 1;
            nodeCount++;
    
            edgeCount += graph[node].size();
    
            for (int next : graph[node]) {
                if (!visited[next]) {
                    dfs(next, graph, visited, nodeCount, edgeCount);
                }
            }
        }
    
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> graph(n);
    
            for (auto& edge : edges) {
                int a = edge[0];
                int b = edge[1];
    
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
    
            vector<int> visited(n, 0);
    
            int answer = 0;
    
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    int nodeCount = 0;
                    int edgeCount = 0;
    
                    dfs(i, graph, visited, nodeCount, edgeCount);
    
                    edgeCount = edgeCount / 2;
    
                    int neededEdges = nodeCount * (nodeCount - 1) / 2;
    
                    if (edgeCount == neededEdges) {
                        answer++;
                    }
                }
            }
    
            return answer;
        }
    };