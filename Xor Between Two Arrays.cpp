// Create Node data type
struct Node{
    Node* links[32];
    bool flag;
    Node(){
        links[0] = NULL;
        links[1] = NULL;
        flag=false;
    }
};


// Creating Trie
class Trie{
    public:
        Node* root = new Node();
        
        // Inseting element in trie in it's binary representation
        void insert(vector<int> binaryDigits){
            Node* node = root;
            for(auto digit: binaryDigits){
                if(node->links[digit]==NULL){
                    node->links[digit] = new Node();
                }
                node = node->links[digit];
            }
            node->flag = true;
        }
        
        // Getting max Xor of given element(num) with any element of trie
        int getMaxXor(vector<int> num){
            int ans=0;
            Node* node = root;
            int placeVal=31;
            int idx=0;
            while(node!=NULL){
                if(node->links[!num[idx]]!=NULL){
                    ans+=pow(2,placeVal);
                    node = node->links[!num[idx]];
                }
                else node = node->links[num[idx]];
                placeVal--;
                idx++;
            }
            return ans;
        }
};


// Extrating Binary digits
vector<int> getBinary(int num){
    vector<int> ans(32,0);
    int idx = 31;
    while(num){
        ans[idx] = num%2;
        num/=2;
        idx--;
    }
    return ans;
}

// Main Solution function
int Solution::solve(vector<int> &A, vector<int> &B) {
    
    // Creating trie object
    Trie trie;
    
    // defining maxXor
    int maxXor = INT_MIN;
    
    // traversing through A
    for(auto a: A){
        
        // Storing a in trie in it's binary representation
        trie.insert(getBinary(a));
    }
    
    // traversing through B
    for(auto b: B){
        
        // Converting b into it's binary representation
        vector<int> b_binaryRepresentation = getBinary(b);
        
        // Getting max Xor for b
        maxXor=max(maxXor, trie.getMaxXor(b_binaryRepresentation));
    }
    
    // Final ans
    return maxXor;
}
