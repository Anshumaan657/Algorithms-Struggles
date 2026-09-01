class Solution {
    public:
        struct State {
            int row;
            int col;
            int energyLeft;
            int collected;
            int moves;
        };
    
        int minMoves(vector<string>& classroom, int energy) {
            int rows = classroom.size();
            int columns = classroom[0].size();
    
            int startRow = 0;
            int startCol = 0;
            int litterCount = 0;
    
            vector<vector<int>> litterIndex(
                rows,
                vector<int>(columns, -1)
            );
    
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < columns; col++) {
                    if (classroom[row][col] == 'S') {
                        startRow = row;
                        startCol = col;
                    }
    
                    if (classroom[row][col] == 'L') {
                        litterIndex[row][col] = litterCount;
                        litterCount++;
                    }
                }
            }
    
            int totalMasks = 1 << litterCount;
            int allCollected = totalMasks - 1;
    
            vector<vector<vector<vector<bool>>>> visited(
                rows,
                vector<vector<vector<bool>>>(
                    columns,
                    vector<vector<bool>>(
                        energy + 1,
                        vector<bool>(totalMasks, false)
                    )
                )
            );
    
            queue<State> q;
    
            q.push({
                startRow,
                startCol,
                energy,
                0,
                0
            });
    
            visited[startRow][startCol][energy][0] = true;
    
            int rowChange[4] = {-1, 1, 0, 0};
            int colChange[4] = {0, 0, -1, 1};
    
            while (!q.empty()) {
                State current = q.front();
                q.pop();
    
                if (current.collected == allCollected) {
                    return current.moves;
                }
    
                if (current.energyLeft == 0) {
                    continue;
                }
    
                for (int direction = 0; direction < 4; direction++) {
                    int newRow =
                        current.row + rowChange[direction];
    
                    int newCol =
                        current.col + colChange[direction];
    
                    if (newRow < 0 || newRow >= rows) {
                        continue;
                    }
    
                    if (newCol < 0 || newCol >= columns) {
                        continue;
                    }
    
                    if (classroom[newRow][newCol] == 'X') {
                        continue;
                    }
    
                    int newEnergy = current.energyLeft - 1;
                    int newCollected = current.collected;
    
                    if (classroom[newRow][newCol] == 'R') {
                        newEnergy = energy;
                    }
    
                    if (classroom[newRow][newCol] == 'L') {
                        int index = litterIndex[newRow][newCol];
    
                        newCollected =
                            newCollected | (1 << index);
                    }
    
                    if (visited[newRow][newCol]
                               [newEnergy][newCollected]) {
                        continue;
                    }
    
                    visited[newRow][newCol]
                           [newEnergy][newCollected] = true;
    
                    q.push({
                        newRow,
                        newCol,
                        newEnergy,
                        newCollected,
                        current.moves + 1
                    });
                }
            }
    
            return -1;
        }
    };