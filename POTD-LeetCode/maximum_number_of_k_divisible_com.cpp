class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int components = 0;
        
        function<long long(int, int)> dfs = [&](int node, int parent) -> long long {
            long long sum = values[node];
            
            for (int child : adj[node]) {
                if (child == parent) continue;
                
                sum += dfs(child, node);
            }
            
            sum %= k;
            
            if (sum == 0) {
                components++;
                return 0; 
            }
            
            return sum;
        };
        
        dfs(0, -1);
        
        return components;
    }
};