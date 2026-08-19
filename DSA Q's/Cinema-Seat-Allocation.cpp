class Solution {
    public:
        int maxNumberOfFamilies(
            int n,
            vector<vector<int>>& reservedSeats
        ) {
            // row -> set of reserved seats in that row
            unordered_map<int, unordered_set<int>> reservedByRow;
    
            for (vector<int>& seat : reservedSeats) {
                int row = seat[0];
                int seatNumber = seat[1];
    
                reservedByRow[row].insert(seatNumber);
            }
    
            // Every row with no reserved seats can fit two families.
            int untouchedRows = n - reservedByRow.size();
            int answer = untouchedRows * 2;
    
            // Process only rows containing reserved seats.
            for (auto& rowData : reservedByRow) {
                unordered_set<int>& reserved = rowData.second;
    
                bool leftBlockFree = true;    // Seats 2, 3, 4, 5
                bool middleBlockFree = true;  // Seats 4, 5, 6, 7
                bool rightBlockFree = true;   // Seats 6, 7, 8, 9
    
                for (int seat = 2; seat <= 5; seat++) {
                    if (reserved.count(seat)) {
                        leftBlockFree = false;
                    }
                }
    
                for (int seat = 4; seat <= 7; seat++) {
                    if (reserved.count(seat)) {
                        middleBlockFree = false;
                    }
                }
    
                for (int seat = 6; seat <= 9; seat++) {
                    if (reserved.count(seat)) {
                        rightBlockFree = false;
                    }
                }
    
                // Left and right blocks do not overlap.
                if (leftBlockFree && rightBlockFree) {
                    answer += 2;
                }
                else if (leftBlockFree ||
                         middleBlockFree ||
                         rightBlockFree) {
                    answer += 1;
                }
            }
    
            return answer;
        }
    };