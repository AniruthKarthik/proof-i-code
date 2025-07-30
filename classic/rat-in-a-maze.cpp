#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class RatInAMaze {
private:
    const vector<int> dRow = {1, 0, 0, -1}; // D, L, R, U
    const vector<int> dCol = {0, -1, 1, 0};
    const string directions = "DLRU";
    
    void print_current_state(const vector<vector<int>>& maze,const vector<vector<int>>& visited,int rat_row, int rat_col, const string& current_path) {
        int n = maze.size();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        cout << "Current Path: " << current_path << "\n";
        cout << "Rat Position: (" << rat_row << ", " << rat_col << ")\n\n";
        
        cout << " ";
        for (int j = 0; j < n; j++) cout << "+---";
        cout << "+\n";
        for (int i = 0; i < n; i++) {
            cout << "|";
            for (int j = 0; j < n; j++) {
                char cell;
                if (i == rat_row && j == rat_col) {
                    cell = 'R';
                } else if (maze[i][j] == 0) {
                    cell = '#';
                } else if (visited[i][j] == 1) {
                    cell = 'x'; 
                } else {
                    cell = ' '; 
                }
                cout << " " << cell << " |";
            }
            cout << "\n ";
            for (int j = 0; j < n; j++) cout << "+---";
            cout << "+\n";
        }
        cout << "\n";
    }
    
    void explore(int row, int col, const vector<vector<int>>& maze, int size,vector<vector<int>>& visited, string current_path, vector<string>& all_paths) {

        print_current_state(maze, visited, row, col, current_path);
        if (row == size - 1 && col == size - 1) {
            visited[row][col] = 1;
            print_current_state(maze, visited, row, col, current_path);
            all_paths.push_back(current_path);
            cout << "The rat has escaped the maze....Press Enter to continue\n";
            cin.get();
            visited[row][col] = 0;
            return;
        }
        visited[row][col] = 1;
        print_current_state(maze, visited, row, col, current_path);
        cout << "Press Enter to continue...";
        cin.get();

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
        visited[row][col] = 0;
        
        print_current_state(maze, visited, row, col, current_path);
        cin.get();
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
int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 1}
    };
    RatInAMaze rat;
    vector<string> paths = rat.find_all_paths(maze, 5);
    if (paths.empty()) {
        cout << "-1\n";
        return 0;
    }
    sort(paths.begin(), paths.end());
    cout << "\nAll possible paths:\n";
    for (const string& p : paths) {
        cout << p << '\n';
    }
    return 0;
}
