#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getLongestIncreasingPath(int n, int m, const vector<vector<int>>& matrixs) {
    vector<vector<int>> dp(n, vector<int>(m));
    
    int max_in_dp = 0;
    
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            int max_adjacent_in_dp = 0;
            
            // check left
            if (col - 1 >= 0 && matrixs[row][col] < matrixs[row][col - 1]) {
                max_adjacent_in_dp = max(max_adjacent_in_dp, dp[row][col - 1]);
            }
            
            // check right
            if (col + 1 < m && matrixs[row][col] < matrixs[row][col + 1]) {
                max_adjacent_in_dp = max(max_adjacent_in_dp, dp[row][col + 1]);
            }
            
            // check up
            if (row - 1 >= 0 && matrixs[row][col] < matrixs[row - 1][col]) {
                max_adjacent_in_dp = max(max_adjacent_in_dp, dp[row - 1][col]);
            }
            
            // check down
            if (row + 1 < n && matrixs[row][col] < matrixs[row + 1][col]) {
                max_adjacent_in_dp = max(max_adjacent_in_dp, dp[row + 1][col]);
            }
            
            // + 1 because zero distance is impossible
            dp[row][col] = max_adjacent_in_dp + 1;
            
            max_in_dp = dp[row][col] > max_in_dp ? dp[row][col] : max_in_dp;
        }
    }
    
    return max_in_dp;
}

int readInt() {
    int x;
    cin >> x;
    return x;
}

vector<int> readList(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

vector<vector<int>> readMatrix(int n, int m) {
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        matrix[i] = readList(m);
    }
    return matrix;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix = readMatrix(n, m);
    cout << getLongestIncreasingPath(n, m, matrix);
}
