#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

size_t getLongestIncreasingPath(size_t n, size_t m, const vector<vector<size_t>>& matrixs) {
    vector<vector<size_t>> dp(n, vector<size_t>(m));
    
    // accepts starting coordinates
    std::function<size_t(int, int)> dfs;
    
    dfs = [&](int row, int col) {
        if (dp[row][col] > 0) {
            return dp[row][col];
        }
        
        size_t max_route = 0;
        
        // check left
        if (col - 1 >= 0 && matrixs[row][col] < matrixs[row][col - 1]) {
            max_route = dfs(row, col - 1) + 1;
        }
        
        // check right
        if (col + 1 < m && matrixs[row][col] < matrixs[row][col + 1]) {
            max_route = std::max(dfs(row, col + 1) + 1, max_route);
        }
        
        // check up
        if (row - 1 >= 0 && matrixs[row][col] < matrixs[row - 1][col]) {
            max_route = std::max(dfs(row - 1, col) + 1, max_route);
        }
        
        // check down
        if (row + 1 < n && matrixs[row][col] < matrixs[row + 1][col]) {
            max_route = std::max(dfs(row + 1, col) + 1, max_route);
        }
        
        // if couldn't move anywhere len is 1
        return max_route > 0 ? max_route : 1;
    };
    
    size_t total_max = 1;
    
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            if (dp[row][col] == 0) {
                size_t route_len = dfs(row, col);
                
                total_max = total_max < route_len ? route_len : total_max;
            }
        }
    }
    
    return total_max;
}

int readInt() {
    int x;
    cin >> x;
    return x;
}

vector<size_t> readList(int n) {
    vector<size_t> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

vector<vector<size_t>> readMatrix(int n, int m) {
    vector<vector<size_t>> matrix(n, vector<size_t>(m));
    for (int i = 0; i < n; i++) {
        matrix[i] = readList(m);
    }
    return matrix;
}

int main() {
    int n, m;
    
    cin >> n >> m;
    
    cout << getLongestIncreasingPath(n, m, readMatrix(n, m));
    
    return 0;
}
