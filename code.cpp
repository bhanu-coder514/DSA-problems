#include <bits/stdc++.h> 
bool isSafe(int newx,int newy,vector < vector < int >> & arr,vector<vector<bool>> &v,int n){
    if((newx >=0 && newx < n) && (newy >= 0 && newy < n) && (arr[newx][newy] == 1) && (v[newx][newy] != 1)){
        return true;
    }
    else{
        return false;
    }
}
void solve(int x,int y,vector < vector < int >> & arr,vector<string> &ans ,vector<vector<bool>> &v,string path,int n){
    // base case 
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    v[x][y] = 1;

    // D L R U
    // down
    if(isSafe(x+1,y,arr,v,n)){
        solve(x+1,y,arr,ans,v,path + 'D',n);
    }

    // left
    if(isSafe(x,y-1,arr,v,n)){
        solve(x,y-1,arr,ans,v,path + 'L',n);
    }

    // right
    if(isSafe(x,y+1,arr,v,n)){
        solve(x,y+1,arr,ans,v,path + 'R',n);
    }

    // up
    if(isSafe(x-1,y,arr,v,n)){
        solve(x-1,y,arr,ans,v,path + 'U',n);
    }


    // while backtracking mark unvisited
    v[x][y] = 0;

}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";

    if(arr[0][0] == 0){
        return ans;
    }

    solve(0,0,arr,ans,visited,path,n);
    sort(ans.begin(),ans.end());
    return ans;
}