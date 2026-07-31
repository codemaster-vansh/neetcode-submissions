class NumMatrix {
    vector<vector<int>> prefMatrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        prefMatrix.resize(m + 1, vector<int> (n + 1, 0));

        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                prefMatrix[i + 1][j + 1] = prefMatrix[i + 1][j] + prefMatrix[i][j + 1] - prefMatrix[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum1 = prefMatrix[row1][col1];
        int sum2 = prefMatrix[row2 + 1][col1];
        int sum3 = prefMatrix[row1][col2 + 1];
        int sum4 = prefMatrix[row2 + 1][col2 + 1];

        return sum4 - sum2 - sum3 + sum1;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */