vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    
    // size of matix A
    int M = A.size();
    int N = A.back().size();
    
    // no. of elements in matrix A = M*N
    int size = M*N;
    
    // creating vector containing ans
    vector<int> ans;
    
    // traversing through matrix A in spiral order
    int i=0;
    while(true){
        // traversing in right -> direction from colm = (i to N-i-1) in row = i
        for(int colm = i; colm < N-i; colm++){
            ans.push_back( A[i][colm] );
        }
        
        if(ans.size() == size) break;
        
        // traversing in down direction from row = (i+1 to M-i-1) in colm = N-i-1
        for(int row = i+1; row < M-i; row++){
            ans.push_back( A[row][N-i-1] );
        }
        
        if(ans.size() == size) break;
        
        
        // traversing in left <- direction from colm = (N-i-2 to i) in row = M-i-1
        for(int colm = N-i-2; colm >=i; colm--){
            ans.push_back( A[M-i-1][colm] );
        }
        
        if(ans.size() == size) break;
        
        
        // traversing in up direction from row = (N-i-2 to i+1) in colm = i
        for(int row = M-i-2; row > i; row--){
            ans.push_back( A[row][i] );
        }
        
        // incrementing i
        i++;
        
        if(ans.size() == size) break;

    }
    
    // ans
    return ans;
}
