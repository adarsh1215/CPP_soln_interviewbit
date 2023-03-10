int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> hash;                 // defining unordered has map
    for(auto i:A){
        hash[B^i]=1;                             // storing element= B^i so that element^i=B
    }
    int ans=0;                                   // stores total no of unorderd pairs
    for(auto i:A){
        if(hash[i]==1){                          // chechking which element of has map present in array
            ans++;
        }
    }
    return ans/2;                                // ans will be total no of ordered pairs so returned ans/2
}
