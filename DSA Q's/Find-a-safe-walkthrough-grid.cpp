#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        health -= grid[0][0];

        if (health <= 0) return false;

        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        best[0][0] = health;
        q.push({0, 0});

        int dirs[5] = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) {
                return true;
            }

            for (int k = 0; k < 4; k++) {
                int nr = r + dirs[k];
                int nc = c + dirs[k + 1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                int newHealth = best[r][c] - grid[nr][nc];

                if (newHealth <= 0) continue;

                if (newHealth > best[nr][nc]) {
                    best[nr][nc] = newHealth;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
};