class Solution {
    public:
        vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
            vector<vector<int>> graph(n);
    
            for (auto edge : invocations) {
                int a = edge[0];
                int b = edge[1];
    
                graph[a].push_back(b);
            }
    
            vector<bool> suspicious(n, false);
    
            queue<int> q;
            q.push(k);
            suspicious[k] = true;
    
            while (!q.empty()) {
                int method = q.front();
                q.pop();
    
                for (int nextMethod : graph[method]) {
                    if (suspicious[nextMethod] == false) {
                        suspicious[nextMethod] = true;
                        q.push(nextMethod);
                    }
                }
            }
    
            for (auto edge : invocations) {
                int a = edge[0];
                int b = edge[1];
    
                if (suspicious[a] == false && suspicious[b] == true) {
                    vector<int> allMethods;
    
                    for (int i = 0; i < n; i++) {
                        allMethods.push_back(i);
                    }
    
                    return allMethods;
                }
            }
    
            vector<int> answer;
    
            for (int i = 0; i < n; i++) {
                if (suspicious[i] == false) {
                    answer.push_back(i);
                }
            }
    
            return answer;
        }
    };