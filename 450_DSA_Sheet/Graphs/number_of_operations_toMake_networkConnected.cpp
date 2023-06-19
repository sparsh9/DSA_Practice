// Approach (Using the Disjoint set DS)
// We initially know that to connect n different components, we require n-1 edges or connections
// so let this be as requiredEdges = n-1
// Now we are said that only one edge can be removed and used elsewhere, no imaginary edge can be used
// and at the same time, the edge we remove from some component, that component must still be a component even after edge removal
// so we calculate total extra edges at all the components and if extraedges >= requiredEdges
// then only it is possible else -1
// also to calculate extra edges, if some components have same ultimate parent, then it means there is an extra edge

// Code Snippet for Disjoint set
class Disjoint_Set{
private:
    vector<int>parent;
    vector<int>rank;
public:
    Disjoint_Set(int n){
        //for 0 based indexing
        parent.resize(n);
        rank.resize(n,0);
        for(int i{0};i<n;++i){
            parent.at(i)=i;
        }
    }
    // Ultimate parent
    int findUPar(int node){
        if(parent.at(node)==node)
            return node;
        return parent.at(node)=findUPar(parent.at(node));
    }

    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u==ulp_v) return ;
        
        if(rank.at(ulp_u)<rank.at(ulp_v)){
            parent.at(ulp_u)=ulp_v;
        }
        else if(rank.at(ulp_u)>rank.at(ulp_v)){
            parent.at(ulp_v)=ulp_u;
        }else{
            parent.at(ulp_v)=ulp_u;
            rank.at(ulp_u)++;
        }
    }

    int components(int size){
        int count=0;
        for(int i{0};i<size;++i){
            if(i==parent.at(i))
                count++;
        }
        return count;
    }
};

// Main code solution
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint_Set ds(n);
        int extraEdges=0;
        for(auto connection:connections){
            int src=connection.at(0);
            int dest=connection.at(1);
       
            if(ds.findUPar(src)==ds.findUPar(dest)){
                extraEdges++;
                continue;
            }
            ds.unionByRank(src,dest);
        }

        int requiredEdges=ds.components(n)-1;
        
        return extraEdges>=requiredEdges?requiredEdges:-1;
    }
};