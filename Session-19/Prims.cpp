#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Define DSU inside Solution
    class DSU {
        vector<int> parent, size;
    public:
        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]); // Path compression
            return parent[x];
        }

        bool unite(int a, int b) {
            int rootA = find(a);
            int rootB = find(b);

            if (rootA == rootB) return false; // Already connected

            // Union by size
            if (size[rootA] < size[rootB]) swap(rootA, rootB);

            parent[rootB] = rootA;
            size[rootA] += size[rootB];
            return true;
        }
    };

  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        DSU dsu(V);
        int mst_weight = 0, mst_edges = 0;

        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dsu.unite(u, v)) {
                mst_weight += w;
                mst_edges++;
                if (mst_edges == V - 1) break; // MST complete
            }
        }
        return mst_weight;
    }
};
