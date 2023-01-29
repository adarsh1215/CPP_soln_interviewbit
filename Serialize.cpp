string Solution::serialize(vector<string> &A) {
    string dig="0123456789";
    string ans="";
    for(auto i:A){
        string size;
        int len=i.size();
        vector<char> length;
        while(len){
            length.push_back(dig[len%10]);
            len/=10;
        }
        while(!length.empty()){
            size.push_back(length.back());
            length.pop_back();
        }
        ans+=i+size+'~';
    }
    return ans;
}
