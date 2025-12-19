class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& meet : meetings) {
            adj[meet[0]].push_back({meet[1], meet[2]});
            adj[meet[1]].push_back({meet[0], meet[2]});
        }

        vector<int> earliest(n, INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            if (t > earliest[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int meetTime = edge.second;

                if (meetTime >= t && meetTime < earliest[v]) {
                    earliest[v] = meetTime;
                    pq.push({meetTime, v});
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (earliest[i] != INT_MAX) {
                result.push_back(i);
            }
        }
        return result;
    }
};