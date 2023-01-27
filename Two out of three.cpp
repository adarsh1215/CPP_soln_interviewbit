vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_map<int,int> hash;                   // hash map to store element with their count
    unordered_map<int,int> hashB;                  // hash map to chech if element is visited in B or not
    unordered_map<int,int> hashC;                  // hash map to chech if element is visited in C or not
    vector<int> ans;
    //-----------------------------------------------------------------------------------------------------------------------
    for(auto i:A) hash[i]=1;                       // storing element appeared in A
    //-----------------------------------------------------------------------------------------------------------------------
    for(auto i:B){                                 // hash[i]=1 if it's only present in A
        if(hashB[i]!=1){                           // hash[i]=2 if it's present in both A and B
            hash[i]++;
            hashB[i]=1;
        }
    }
    //-----------------------------------------------------------------------------------------------------------------------
    for(auto i:C){                                 // hash[i]=1 if it's only present in A
        if(hashC[i]!=1){                           // hash[i]=2 if it's present in both A and B
            hash[i]++;                             // hash[i]=3 if it's present in A, B and C
            hashC[i]=1;
        }
    }
    //-----------------------------------------------------------------------------------------------------------------------
    for(auto i:hash){                              // storing element with count >=2 in hash 
        if(i.second>=2){
            ans.push_back(i.first);
        }
    }
    //-----------------------------------------------------------------------------------------------------------------------
    sort(ans.begin(), ans.end());                 // sorting the stored elements
    return ans;
}
