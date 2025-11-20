class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });
        
        int result = 0;
        int p1 = -1, p2 = -1;

        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            
            bool has_p1 = (p1 >= start && p1 <= end);
            bool has_p2 = (p2 >= start && p2 <= end);
            
            if (has_p1 && has_p2) {
                continue;
            } else if (has_p2) {
                p1 = p2;
                p2 = end;
                result++;
            } else {
                p1 = end - 1;
                p2 = end;
                result += 2;
            }
        }
        
        return result;
    }
};