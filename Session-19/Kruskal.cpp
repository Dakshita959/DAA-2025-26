#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findParent(int node, vector<int>& parent) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(u, parent);
        v = findParent(v, parent);
        
        if(u == v) return;
        //z
        if(rank[u] < rank[v]) {
            parent[u] = v;
        } else if(rank[v] < rank[u]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });
        vector<int> parent(V), rank(V, 0);
        for(int i = 0; i < V; i++) parent[i] = i;
        int mstWeight = 0;
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            
            int pu = findParent(u, parent);
            int pv = findParent(v, parent);
            
            if(pu != pv) { // if they belong to different sets
                mstWeight += w;
                unionSet(pu, pv, parent, rank);
            }
        }
        
        return mstWeight;
    }
};