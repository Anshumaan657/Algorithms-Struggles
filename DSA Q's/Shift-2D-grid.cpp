class Solution{
    public:
    int m = grid.size();
    int n = grid[0].size();
    int total = m * n;
    int k = k % total;
    vector<int> temp;
    for (int i =0; i<m; i++){
        for(int j = 0; j<n; j++){
            temp.push_back(grid[i][j]);
        }
    }
    vector<vector<int>> answer(m, vector<int>(n));
    for(int i = 0; i<total; i++){
        int newIndex = (i+k)%total;
        int row = newIndex/n;
        int col = newIndex%n;
        answer[row][col]=temp[i];
    }

};