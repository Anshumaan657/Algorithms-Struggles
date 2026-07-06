#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }

            return a[0] < b[0];
        });

        int remaining = 0;
        int maxEnd = 0;

        for (int i = 0; i < intervals.size(); i++) {
            int end = intervals[i][1];

            if (end <= maxEnd) {
                continue;
            }

            remaining++;
            maxEnd = end;
        }

        return remaining;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals = {
        {1, 4},
        {3, 6},
        {2, 8}
    };

    cout << sol.removeCoveredIntervals(intervals) << endl;

    return 0;
}