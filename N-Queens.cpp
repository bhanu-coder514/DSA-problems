class Solution {
public:

    bool issafe(int col,int row,vector<string> &boards,int n){
        int x = row;
        int y = col;

        // check for row left
        while(y >= 0){
            if(boards[x][y] == 'Q'){
                return false;
            }
            y--;
        }

        // check for upper left diagonal
        x = row , y = col;
        while(y >= 0 && x >= 0){
            if(boards[x][y] == 'Q'){
                return false;
            }
            x--;
            y--;
        }

        // check for lover left diagonal
        x = row , y = col;
        while(y >= 0 && x < n){
            if(boards[x][y] == 'Q'){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }

    void solve(int col,vector<string> &boards,vector<vector<string>> &ans,int n){
        // base case 
        if(col == n){
            // addsol(boards,ans,n);
            ans.push_back(boards);
            return;
        }

        for(int row = 0; row < n; row++){
            if(issafe(col,row,boards,n)){
                boards[row][col] = 'Q';
                
                // recursive call
                solve(col+1,boards,ans,n);

                // backtrack
                boards[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> boards(n,string(n,'.'));
        vector<vector<string>> ans;

        solve(0,boards,ans,n);

        return ans;
    }
};