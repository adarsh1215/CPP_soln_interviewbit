vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    unordered_map<int, int> hash;                // map to store frequency of elements in particular window
    
    if(B>A.size()) return ans;                   // entering first B elements in map
    
    for(int i=0; i<B; i++){
        hash[A[i]]++;
    }
    ans.push_back(hash.size());
    
    for(int i=B; i<A.size(); i++){
        if(hash[A[i-B]]==1) hash.erase(A[i-B]);// to check if elements just previous to curr window is present in curr window
        else hash[A[i-B]]--;                   // decreasing frequency of just previous element to curr window by 1
        hash[A[i]]++;                          // adding new element to map 
        ans.push_back(hash.size());            // storing no of distinct element in window
    }
    return ans;
}
