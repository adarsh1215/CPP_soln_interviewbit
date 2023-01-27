int Solution::solve(vector<int> &A) {
    unordered_map<int,int> hash;                   // defining hash map to store count of elements
    int mini=INT_MAX;                              // initially min idx set to INT_MAX
    for(int i=A.size()-1; i>=0; i--){              // traversing trogh array in reverse direction
        hash[A[i]]++;                              
        if(hash[A[i]]>1){
            mini=min(mini,i);                      // updating min idx to current min idx if count of element is > 1
        }
    }
    if(mini==INT_MAX) return -1;
    return A[mini];
}