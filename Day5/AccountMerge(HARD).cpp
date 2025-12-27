// Given a list of accounts where each element accounts [ i ] is a list of strings, where the first element account [ i ][ 0 ]  is a name, 
// and the rest of the elements are emails representing emails of the account.
// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts.
// Note that even if two accounts have the same name, they may belong to different people as people could have the same name.
// A person can have any number of accounts initially, but all of their accounts definitely have the same name.
// After merging the accounts, return the accounts in the following format: the first element of each account is the name,
// and the rest of the elements are emails in sorted order.

//https://leetcode.com/problems/accounts-merge/description/

//User function Template for C++
class DisjointSet{
    public:
    vector<int> parent, size, rank;
    
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        
        for(int i=0;i<n+1;i++) parent[i]=i;
    }
    
    int findUltParent(int node){
        if(parent[node]==node){
            return node;
        }
        
        return parent[node] = findUltParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int pv = findUltParent(v);
        int pu = findUltParent(u);
        
        if(pv == pu) return;
        if(size[pv]>size[pu]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pu];
        }
        
    }
    
    void unionByRank(int u, int v){
        int pv = findUltParent(v);
        int pu = findUltParent(u);
        
        if(pv == pu) return;
        
        if(rank[pv]==rank[pu]){
            parent[pu]=pv;
            rank[pv]++;
        }
        else if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
        }
    }
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        unordered_map<string,int> mp;
        int n = accounts.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail]=i;
                }else{
                    ds.unionBySize(i,mp[mail]);
                }
            }
        }
        
        // step2: merge mails
        
        vector<string> mergedMail[n];
        for(auto m : mp){
            string mail = m.first;
            int node = ds.findUltParent(m.second);
            mergedMail[node].push_back(mail);
        }
        
        // step3: 
        
        vector<vector<string>> res;
        int count=0;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]) temp.push_back(it);
            res.push_back(temp);
        }
        
        return res;     
    }
};
