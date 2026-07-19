class Solution{
    public:
    int answer = 0;
    long long dfs(TreeNode* node){
        if (node == NULL){
            return 0;
        }
        long long leftMax = dfs(node->left);
        long long rightMax = dfs(node->right);
        long long subTreeMax = max((long long) node->val, max(leftMax, rightMax));
        if (node->val == subTreeMax)
        {
            answer++;
        }
        return subTreeMax;
    
    }
    
int countDominantNodes(TreeNode* root){
    TreeNode* norlavetic = root;
    dfs(norlavetic);
    return answer;
}
};