void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    // vector to store row of zeros
    unordered_map<int, int> zerosRow;
    
    // vector to store column of zeros
    unordered_map<int, int> zerosColm;
    
    // Traversing through matrix
    for(int row=0; row<A.size(); row++){
        for(int colm=0; colm<A.back().size(); colm++){
            
            // Checking if element is zero and storing zeros position
            if(A[row][colm]==0){
                zerosRow[row]++;
                zerosColm[colm]++;
            }
        }
    }
    
    // Traversing through zerosRow
    for(auto zr: zerosRow){
        
        // setting zr.first row in A = 0
        for(int colm=0; colm<A.back().size(); colm++){
            A[zr.first][colm] = 0;
        }
    }
    // Traversing through zerosColm
    for(auto zc: zerosColm){
        
        // setting zc.first column in A = 0
        for(int row=0; row<A.size(); row++){
            A[row][zc.first] = 0;
        }
    }
}
