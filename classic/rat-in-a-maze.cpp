#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <queue>
using namespace std;

class RatInAMaze {
private:
    const vector<int> dRow = {1, 0, 0, -1}; // D, L, R, U
    const vector<int> dCol = {0, -1, 1, 0};
    const string directions = "DLRU";

    void explore(int row, int col, const vector<vector<int>>& maze, int size,
                 vector<vector<int>>& visited, string current_path, vector<string>& all_paths) {
        if (row == size - 1 && col == size - 1) {
            all_paths.push_back(current_path);
            return;
        }

        visited[row][col] = 1;

        for (int dir = 0; dir < 4; dir++) {
            int next_row = row + dRow[dir];
            int next_col = col + dCol[dir];

            if (next_row >= 0 && next_col >= 0 &&
                next_row < size && next_col < size &&
                maze[next_row][next_col] == 1 &&
                visited[next_row][next_col] == 0) {
                explore(next_row, next_col, maze, size, visited,
                        current_path + directions[dir], all_paths);
            }
        }

        visited[row][col] = 0; // backtrack
    }

public:
    vector<string> find_all_paths(vector<vector<int>>& maze, int size) {
        vector<string> all_paths;
        if (maze[0][0] == 0 || maze[size - 1][size - 1] == 0) return all_paths;

        vector<vector<int>> visited(size, vector<int>(size, 0));
        explore(0, 0, maze, size, visited, "", all_paths);
        return all_paths;
    }
};

class MazeGenerator {
private:
    int m, n;
    vector<vector<int>> maze;
    const vector<int> dRow = {1, 0, -1, 0}; // D, R, U, L
    const vector<int> dCol = {0, 1, 0, -1};

    bool isValid(int row, int col) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }

    // Check if there's a path from (0,0) to (m-1,n-1) using BFS
    bool hasPath() {
        if (maze[0][0] == 0 || maze[m-1][n-1] == 0) return false;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            if (row == m-1 && col == n-1) return true;
            
            for (int i = 0; i < 4; i++) {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];
                
                if (isValid(newRow, newCol) && !visited[newRow][newCol] && maze[newRow][newCol] == 1) {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
        return false;
    }

    // Create a guaranteed path from start to end (simple L-shaped or random walk)
    void createGuaranteedPath() {
        // Method 1: Simple L-path (go right then down, or down then right)
        if (rand() % 2 == 0) {
            // Go right first, then down
            for (int j = 0; j < n; j++) maze[0][j] = 1;
            for (int i = 0; i < m; i++) maze[i][n-1] = 1;
        } else {
            // Go down first, then right  
            for (int i = 0; i < m; i++) maze[i][0] = 1;
            for (int j = 0; j < n; j++) maze[m-1][j] = 1;
        }
    }

    // Generate a completely random maze
    void generateRandomMaze(double pathProbability = 0.4) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Random decision: make this cell a path or wall
                maze[i][j] = (rand() / (double)RAND_MAX < pathProbability) ? 1 : 0;
            }
        }
        // Always ensure start and end are open
        maze[0][0] = 1;
        maze[m-1][n-1] = 1;
    }

public:
    MazeGenerator(int rows, int cols)
        : m(rows), n(cols), maze(rows, vector<int>(cols, 0)) {}

    vector<vector<int>> generate(double pathProbability = 0.4, int maxAttempts = 100) {
        int attempts = 0;
        
        do {
            // Generate completely random maze
            generateRandomMaze(pathProbability);
            attempts++;
            
            // If no path exists after several attempts, create a guaranteed path
            if (attempts >= maxAttempts && !hasPath()) {
                cout << "No valid path found after " << maxAttempts << " attempts. Creating guaranteed path...\n";
                createGuaranteedPath();
                break;
            }
            
        } while (!hasPath() && attempts < maxAttempts);
        
        if (attempts < maxAttempts) {
            cout << "Valid maze generated after " << attempts << " attempt(s)\n";
        }
        
        return maze;
    }

    void printMaze() {
        cout << "Maze layout (1 = path, 0 = wall):\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << maze[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // Get statistics about the maze
    void printStats() {
        int pathCount = 0;
        int totalCells = m * n;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (maze[i][j] == 1) pathCount++;
            }
        }
        
        cout << "Maze Stats:\n";
        cout << "Size: " << m << "x" << n << " (" << totalCells << " total cells)\n";
        cout << "Path cells: " << pathCount << " (" << (pathCount*100.0/totalCells) << "%)\n";
        cout << "Wall cells: " << (totalCells - pathCount) << " (" << ((totalCells-pathCount)*100.0/totalCells) << "%)\n";
    }
};

int main() {
    srand(time(0)); // seed random generator

    int size = 6; // square maze (m x m)
    double pathProbability = 0.35; // 35% chance each cell is a path (adjust for difficulty)
    
    cout << "Generating " << size << "x" << size << " maze with " << (pathProbability*100) << "% path probability...\n\n";
    
    MazeGenerator generator(size, size);
    vector<vector<int>> maze = generator.generate(pathProbability);

    cout << "\nGenerated Maze:\n";
    generator.printMaze();
    
    cout << "\n";
    generator.printStats();

    RatInAMaze rat;
    vector<string> paths = rat.find_all_paths(maze, size);

    cout << "\nAll valid paths from (0,0) to (" << size - 1 << "," << size - 1 << "):\n";
    if (paths.empty()) {
        cout << "No path exists! (This shouldn't happen with the new generator)\n";
    } else {
        cout << "Found " << paths.size() << " path(s):\n";
        for (size_t i = 0; i < paths.size() && i < 10; i++) { // Limit output for large path counts
            cout << (i+1) << ". " << paths[i] << "\n";
        }
        if (paths.size() > 10) {
            cout << "... and " << (paths.size() - 10) << " more paths\n";
        }
    }

    return 0;
}
