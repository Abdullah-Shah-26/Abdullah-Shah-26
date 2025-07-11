#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        // dp[i][j][k] represents max cherries when:
        // first path is at (i,j) and second path is at (k,i+j-k)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        
        return max(0, solve(0, 0, 0, grid, dp));
    }
    
private:
    int solve(int i, int j, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int l = i + j - k;  // l is determined by i,j,k
        
        // Check if out of bounds or hitting a thorn
        if(i >= n || j >= n || k >= n || l >= n || 
           grid[i][j] == -1 || grid[k][l] == -1) {
            return -1e8;
        }
        
        // If we've reached the end
        if(i == n-1 && j == n-1) {
            return grid[i][j];
        }
        
        // If already computed
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        
        int cherries = 0;
        // If both paths are at same cell, count cherry only once
        if(i == k && j == l) {
            cherries = grid[i][j];
        } else {
            cherries = grid[i][j] + grid[k][l];
        }
        
        // Try all possible moves
        int maxCherries = -1e8;
        
        // Try moving right or down for both paths
        vector<pair<int,int>> moves = {{0,1}, {1,0}};
        for(const auto& move1 : moves) {
            for(const auto& move2 : moves) {
                int next = solve(i + move1.first, j + move1.second,
                               k + move2.first, grid, dp);
                if(next != -1e8) {
                    maxCherries = max(maxCherries, next);
                }
            }
        }
        
        // If no valid path found
        if(maxCherries == -1e8) {
            return dp[i][j][k] = -1e8;
        }
        
        return dp[i][j][k] = cherries + maxCherries;
    }
}; 