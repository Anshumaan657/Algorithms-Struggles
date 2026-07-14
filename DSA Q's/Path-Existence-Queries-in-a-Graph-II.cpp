class Solution {
    public:
        vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
            vector<pair<int, int>> arr;
    
            for (int i = 0; i < n; i++) {
                arr.push_back({nums[i], i});
            }
    
            sort(arr.begin(), arr.end());
    
            vector<int> position(n);
    
            for (int i = 0; i < n; i++) {
                int originalIndex = arr[i].second;
                position[originalIndex] = i;
            }
    
            vector<int> component(n, 0);
            int comp = 0;
    
            for (int i = 1; i < n; i++) {
                if (arr[i].first - arr[i - 1].first > maxDiff) {
                    comp++;
                }
    
                component[i] = comp;
            }
    
            vector<int> farthest(n);
    
            int right = 0;
    
            for (int left = 0; left < n; left++) {
                while (right + 1 < n && arr[right + 1].first - arr[left].first <= maxDiff) {
                    right++;
                }
    
                farthest[left] = right;
            }
    
            int LOG = 18;
    
            vector<vector<int>> jump(LOG, vector<int>(n));
    
            for (int i = 0; i < n; i++) {
                jump[0][i] = farthest[i];
            }
    
            for (int level = 1; level < LOG; level++) {
                for (int i = 0; i < n; i++) {
                    jump[level][i] = jump[level - 1][jump[level - 1][i]];
                }
            }
    
            vector<int> answer;
    
            for (auto &query : queries) {
                int u = query[0];
                int v = query[1];
    
                int start = position[u];
                int end = position[v];
    
                if (start == end) {
                    answer.push_back(0);
                    continue;
                }
    
                if (start > end) {
                    swap(start, end);
                }
    
                if (component[start] != component[end]) {
                    answer.push_back(-1);
                    continue;
                }
    
                int steps = 0;
                int current = start;
    
                for (int level = LOG - 1; level >= 0; level--) {
                    if (jump[level][current] < end) {
                        current = jump[level][current];
                        steps += (1 << level);
                    }
                }
    
                answer.push_back(steps + 1);
            }
    
            return answer;
        }
    };