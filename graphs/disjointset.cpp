#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

 public:
 DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1,0);
    size.resize(n+1,0);
    for (int i = 0; i < n; i++)
    {
        parent[i]=i;
        rank[i]=0;
    }    
}
int findParent(int node){
    if(node==parent[node]) return node;
    else return parent[node]=findParent(parent[node]);
}
void UnionbyRank(int u, int v){
   int ulp_u = findParent(u);
   int ulp_v = findParent(v);
   if(ulp_u==ulp_v) return;
    if(rank[ulp_u]<rank[ulp_v]) parent[ulp_u]=ulp_v;
    else if(rank[ulp_v]<rank[ulp_u]) parent[ulp_v]=ulp_u;
    else{
        parent[ulp_v]=ulp_u;
        rank[ulp_u]++;
}
}
void UnionBySize(int u, int v){
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);
    if(ulp_u==ulp_v) return;
    if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else{
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
}

};
int main() {

return 0;
}
