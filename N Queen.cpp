bool isSafe(vector<string>& board, int row, int colm){     // isSafe function to chech if current configuration is safe of not
    int n=board.size();
    for(int i=0; i<=colm; i++){                           //checking position of queen accross row
        if(board[row][i]=='Q' && i!=colm) return false;
    }
    
    int rowIterator = row-1;
    int colmIterator = colm-1;
    while(rowIterator>=0 && colmIterator>=0){            // checking upper rigth position of queens
        if(board[rowIterator][colmIterator] == 'Q') return false;
        rowIterator--;
        colmIterator--;
    }
    
    rowIterator = row+1;
    colmIterator = colm-1;
    while(rowIterator<n && colmIterator>=0){            // checking bottom left position of queens
        if(board[rowIterator][colmIterator]=='Q') return false;
        rowIterator++;
        colmIterator--;
    }
    return true;
}
//----------------------------------------------------------------------------------------------------------------------------
void solve(int n, vector<vector<string>>& ans,vector<string> board,int colm){ //solve fun to place queens in board recursively
    
    if(colm == n){                           // checking if all queens are placed
        ans.push_back(board);              // storing correct board in ans
        return;
    }
    
    for(int row = 0; row<n; row++){
        board[row][colm] = 'Q';              // placed queen in board
        if(isSafe(board,row,colm)){
            solve(n,ans,board,colm+1);     // calling solve fun to place queen on next colm
        }
        board[row][colm]='.';
    }
}               
//----------------------------------------------------------------------------------------------------------------------------
vector<vector<string> > Solution::solveNQueens(int A) {
    
    vector<vector<string>> ans;         // ans vector contains all possible boards
    string  str="";
    vector<string> board;               //initialising board with A no. of strings of A size containing '.'
    for(int i=0; i<A; i++){
        str+='.';
    }
    for(int i=0; i<A; i++){
        board.push_back(str);
    }
    solve(A,ans,board,0);
    return ans;
}
                                                        
