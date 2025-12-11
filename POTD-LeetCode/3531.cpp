class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        set<pair<int, int>> buildingSet;
        for (auto& b : buildings) {
            buildingSet.insert({b[0], b[1]});
        }
        
        map<int, vector<int>> byRow; 
        map<int, vector<int>> byCol; 
        
        for (auto& b : buildings) {
            byRow[b[0]].push_back(b[1]);
            byCol[b[1]].push_back(b[0]);
        }
        
        for (auto& [row, cols] : byRow) {
            sort(cols.begin(), cols.end());
        }
        for (auto& [col, rows] : byCol) {
            sort(rows.begin(), rows.end());
        }
        
        int count = 0;
        
        for (auto& b : buildings) {
            int x = b[0];
            int y = b[1];
            
            bool hasAbove = false;
            bool hasBelow = false;
            bool hasLeft = false;
            bool hasRight = false;
            
            if (byCol.count(y)) {
                auto& rows = byCol[y];
                auto it = lower_bound(rows.begin(), rows.end(), x);
                if (it != rows.begin()) {
                    hasAbove = true;
                }
            }
            
            if (byCol.count(y)) {
                auto& rows = byCol[y];
                auto it = upper_bound(rows.begin(), rows.end(), x);
                if (it != rows.end()) {
                    hasBelow = true;
                }
            }
            
            if (byRow.count(x)) {
                auto& cols = byRow[x];
                auto it = lower_bound(cols.begin(), cols.end(), y);
                if (it != cols.begin()) {
                    hasLeft = true;
                }
            }
            
            if (byRow.count(x)) {
                auto& cols = byRow[x];
                auto it = upper_bound(cols.begin(), cols.end(), y);
                if (it != cols.end()) {
                    hasRight = true;
                }
            }
            
            if (hasAbove && hasBelow && hasLeft && hasRight) {
                count++;
            }
        }
        
        return count;
    }
};