class Solution {
public:

    bool isSafe(int row ,int col,vector<vector<char>>& board,char ch){

        int n = board.size();

        for(int i = 0; i<n; i++){
            // check row
            if(board[i][col] == ch){
                return false;
            }

            // check col 
            if(board[row][i] == ch){
                return false;
            }

            // check 3X3 matrix
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int n = board.size();

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){

                // if cell is empty
                if(board[row][col] == '.'){
                    for(char ch = '1'; ch <= '9'; ch++){
                        if(isSafe(row,col,board,ch)){
                            board[row][col] = ch;

                            bool nextSolution = solve(board);

                        if(nextSolution){
                            return true;
                        }
                        else{
                            // backtrack
                            board[row][col] = '.';
                        }
                        }

                    }
                    return false;
                }
            }
        }
        return true;
    }


    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};