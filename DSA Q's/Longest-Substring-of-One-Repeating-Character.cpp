class Solution {
    public:
        struct Node {
            char leftChar;
            char rightChar;
    
            int prefix;
            int suffix;
            int best;
            int length;
        };
    
        vector<Node> tree;
        string currentString;
    
        Node mergeNodes(Node left, Node right) {
            Node result;
    
            result.leftChar = left.leftChar;
            result.rightChar = right.rightChar;
            result.length = left.length + right.length;
    
            result.prefix = left.prefix;
    
            if (left.prefix == left.length &&
                left.rightChar == right.leftChar) {
                result.prefix = left.length + right.prefix;
            }
    
            result.suffix = right.suffix;
    
            if (right.suffix == right.length &&
                left.rightChar == right.leftChar) {
                result.suffix = right.length + left.suffix;
            }
    
            result.best = max(left.best, right.best);
    
            if (left.rightChar == right.leftChar) {
                int joiningLength = left.suffix + right.prefix;
                result.best = max(result.best, joiningLength);
            }
    
            return result;
        }
    
        void build(int node, int left, int right) {
            if (left == right) {
                tree[node] = {
                    currentString[left],
                    currentString[left],
                    1,
                    1,
                    1,
                    1
                };
    
                return;
            }
    
            int middle = left + (right - left) / 2;
    
            build(2 * node, left, middle);
            build(2 * node + 1, middle + 1, right);
    
            tree[node] = mergeNodes(tree[2 * node],
                                    tree[2 * node + 1]);
        }
    
        void update(int node, int left, int right,
                    int index, char newCharacter) {
    
            if (left == right) {
                tree[node] = {
                    newCharacter,
                    newCharacter,
                    1,
                    1,
                    1,
                    1
                };
    
                return;
            }
    
            int middle = left + (right - left) / 2;
    
            if (index <= middle) {
                update(2 * node, left, middle, index, newCharacter);
            } else {
                update(2 * node + 1, middle + 1, right,
                       index, newCharacter);
            }
    
            tree[node] = mergeNodes(tree[2 * node],
                                    tree[2 * node + 1]);
        }
    
        vector<int> longestRepeating(
            string s,
            string queryCharacters,
            vector<int>& queryIndices
        ) {
            currentString = s;
    
            int n = s.size();
            int numberOfQueries = queryIndices.size();
    
            tree.resize(4 * n);
    
            build(1, 0, n - 1);
    
            vector<int> answer;
    
            for (int i = 0; i < numberOfQueries; i++) {
                int index = queryIndices[i];
                char newCharacter = queryCharacters[i];
    
                currentString[index] = newCharacter;
    
                update(1, 0, n - 1, index, newCharacter);
    
                // Root represents the complete string.
                answer.push_back(tree[1].best);
            }
    
            return answer;
        }
    };