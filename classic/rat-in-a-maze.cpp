#include <iostream>
#include <string>
#include <vector>
using namespace std;

// # INCOMPLETE 

bool is_valid(int x,int y,vector<vector<int>>& maze,vector<vector<int>>& visited){

    int n=maze.size();
    return (x>=0 && y>=0 && x<n && y<n && maze[x][y]==1 && visited[x][y]==0);

}

void solve(int x,int y,vector<vector<int>>& maze,int n,vector<string>&paths,string path,vector<vector<int>>& visited){
    if(x==n-1 && y==n-1){
        paths.push_back(path);
        return;
    }

    visited[x][y]=1;

    if(is_valid(x+1 , y, maze, visited)){
        solve(x+1 , y,maze, n, paths, path+'D', visited);
    }
    if(is_valid(x , y-1, maze, visited)){
        solve(x , y-1,maze, n, paths, path+'L', visited);
    }
    if(is_valid(x , y+1, maze, visited)){
        solve(x , y+1,maze, n, paths, path+'R', visited);
    }
    if(is_valid(x-1 , y, maze, visited)){
        solve(x-1 , y,maze, n, paths, path+'U', visited);
    }

    visited[x][y]=0;
}

vector<string>find_paths(vector<vector<int>>& maze,int n){
    vector<string> paths;



    return paths;
}
