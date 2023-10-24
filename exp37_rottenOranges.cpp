#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int freshOranges = 0;
    queue<Point> rottenOranges;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minutes = 0;

    // Count fresh oranges and enqueue rotten oranges
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                rottenOranges.push({i, j});
            } else if (grid[i][j] == 1) {
                freshOranges++;
            }
        }
    }

    while (!rottenOranges.empty() && freshOranges > 0) {
        int size = rottenOranges.size();
        for (int i = 0; i < size; ++i) {
            Point current = rottenOranges.front();
            rottenOranges.pop();

            for (const auto& direction : directions) {
                int newX = current.x + direction[0];
                int newY = current.y + direction[1];

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    rottenOranges.push({newX, newY});
                    freshOranges--;
                }
            }
        }
        minutes++;
    }

    // If there are still fresh oranges left, it's impossible to rot them all
    if (freshOranges > 0) {
        return -1;
    }

    // Subtract 1 because the last round didn't rot any oranges
    return max(0, minutes - 1);
}

int main() {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int minutes = orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << minutes << " minutes" << endl; // Output: 4 minutes
    return 0;
}
