string Solution::solve(string A) {
    vector<pair<int, pair<char, int>>> hash(26);    // vector to store index of first occurance, char, its frequency
    string ans;
    for(int i=0; i<A.size(); i++){
        if(hash[A[i]-'a'].second.second==0){        // storing index 0f first occurance
            hash[A[i]-'a'].first=i;
        }
        hash[A[i]-'a'].second.second++;             // storing frequency of char
        hash[A[i]-'a'].second.first=A[i];           //storing char
    }
    sort(hash.begin(), hash.end());                 // sorting characters based on first occurance
    for(int i=0; i<hash.size(); i++){ 
        if(hash[i].second.second>0){                // to avoid appending invalid garbage value in ans
            ans.push_back(hash[i].second.first);    // appending character
            ans+=to_string(hash[i].second.second);  // appending its frequency
        }
        
    }
    return ans;
}
