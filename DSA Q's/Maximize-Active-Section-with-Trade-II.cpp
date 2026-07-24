class Solution {
    private:
        struct ZeroGroup {
            int start;
            int length;
        };
    
        vector<int> segmentTree;
        int treeSize;
    
        void buildTree(vector<int>& values, int node, int left, int right) {
            if (left == right) {
                segmentTree[node] = values[left];
                return;
            }
    
            int mid = left + (right - left) / 2;
    
            buildTree(values, node * 2, left, mid);
            buildTree(values, node * 2 + 1, mid + 1, right);
    
            segmentTree[node] = max(
                segmentTree[node * 2],
                segmentTree[node * 2 + 1]
            );
        }
    
        int rangeMaximum(
            int node,
            int left,
            int right,
            int queryLeft,
            int queryRight
        ) {
            if (right < queryLeft || left > queryRight) {
                return 0;
            }
    
            if (queryLeft <= left && right <= queryRight) {
                return segmentTree[node];
            }
    
            int mid = left + (right - left) / 2;
    
            int leftAnswer = rangeMaximum(
                node * 2,
                left,
                mid,
                queryLeft,
                queryRight
            );
    
            int rightAnswer = rangeMaximum(
                node * 2 + 1,
                mid + 1,
                right,
                queryLeft,
                queryRight
            );
    
            return max(leftAnswer, rightAnswer);
        }
    
    public:
        vector<int> maxActiveSectionsAfterTrade(
            string s,
            vector<vector<int>>& queries
        ) {
            int n = s.size();
    
            int totalOnes = 0;
    
            for (char character : s) {
                if (character == '1') {
                    totalOnes++;
                }
            }
    
            vector<ZeroGroup> zeroGroups;
            vector<int> previousZeroGroup(n, -1);
    
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    if (i > 0 && s[i - 1] == '0') {
                        zeroGroups.back().length++;
                    } else {
                        zeroGroups.push_back({i, 1});
                    }
                }
    
                previousZeroGroup[i] = zeroGroups.size() - 1;
            }
    
            if (zeroGroups.empty()) {
                return vector<int>(queries.size(), totalOnes);
            }
    
            vector<int> adjacentSum;
    
            for (int i = 0; i + 1 < zeroGroups.size(); i++) {
                int currentSum =
                    zeroGroups[i].length +
                    zeroGroups[i + 1].length;
    
                adjacentSum.push_back(currentSum);
            }
    
            treeSize = adjacentSum.size();
    
            if (treeSize > 0) {
                segmentTree.resize(4 * treeSize);
                buildTree(adjacentSum, 1, 0, treeSize - 1);
            }
    
            vector<int> answer;
    
            for (vector<int>& query : queries) {
                int left = query[0];
                int right = query[1];
    
                int result = totalOnes;
    
                int leftGroupIndex = previousZeroGroup[left];
                int rightGroupIndex = previousZeroGroup[right];
    
                int leftZeroLength = -1;
    
                if (s[left] == '0') {
                    ZeroGroup group = zeroGroups[leftGroupIndex];
    
                    leftZeroLength =
                        group.length -
                        (left - group.start);
                }
    
                int rightZeroLength = -1;
    
                if (s[right] == '0') {
                    ZeroGroup group = zeroGroups[rightGroupIndex];
    
                    rightZeroLength =
                        right - group.start + 1;
                }
    
                int firstCompleteGroup;
    
                if (s[left] == '0') {
                    firstCompleteGroup = leftGroupIndex + 1;
                } else {
                    firstCompleteGroup = leftGroupIndex + 1;
                }
    
                int lastCompleteGroup;
    
                if (s[right] == '1') {
                    lastCompleteGroup = rightGroupIndex;
                } else {
                    lastCompleteGroup = rightGroupIndex - 1;
                }
    
                if (
                    s[left] == '0' &&
                    s[right] == '0' &&
                    leftGroupIndex + 1 == rightGroupIndex
                ) {
                    result = max(
                        result,
                        totalOnes + leftZeroLength + rightZeroLength
                    );
                }
    
                int pairLeft = firstCompleteGroup;
                int pairRight = lastCompleteGroup - 1;
    
                if (
                    treeSize > 0 &&
                    pairLeft <= pairRight
                ) {
                    int bestPair = rangeMaximum(
                        1,
                        0,
                        treeSize - 1,
                        pairLeft,
                        pairRight
                    );
    
                    result = max(result, totalOnes + bestPair);
                }
    
                if (s[left] == '0') {
                    int nextGroup = leftGroupIndex + 1;
    
                    if (nextGroup <= lastCompleteGroup) {
                        int gainedZeros =
                            leftZeroLength +
                            zeroGroups[nextGroup].length;
    
                        result = max(
                            result,
                            totalOnes + gainedZeros
                        );
                    }
                }
    
                if (s[right] == '0') {
                    int previousGroup = rightGroupIndex - 1;
    
                    if (previousGroup >= firstCompleteGroup) {
                        int gainedZeros =
                            zeroGroups[previousGroup].length +
                            rightZeroLength;
    
                        result = max(
                            result,
                            totalOnes + gainedZeros
                        );
                    }
                }
    
                answer.push_back(result);
            }
    
            return answer;
        }
    };