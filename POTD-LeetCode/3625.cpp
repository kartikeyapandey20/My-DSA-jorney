class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0;

        map<pair<int, int>, map<long long, int>> slope_map;

        map<pair<int, int>, map<pair<int, int>, int>> mid_map;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                
                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
                
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                pair<int, int> slope = {dy, dx};

                long long line_val = (long long)points[i][0] * dy - (long long)points[i][1] * dx;
                
                slope_map[slope][line_val]++;

                int mid_x = points[i][0] + points[j][0];
                int mid_y = points[i][1] + points[j][1];
                mid_map[{mid_x, mid_y}][slope]++;
            }
        }

        long long total_combinations = 0;

        for (auto const& [slope, lines] : slope_map) {
            long long total_segments_with_slope = 0;
            vector<int> segment_counts;
            
            for (auto const& [val, count] : lines) {
                segment_counts.push_back(count);
                total_segments_with_slope += count;
            }

            for (int count : segment_counts) {
                total_combinations += (long long)count * (total_segments_with_slope - count);
            }
        }
        total_combinations /= 2;

        long long parallelograms = 0;
        
        for (auto const& [mid, slope_counts] : mid_map) {
            long long total_diagonals = 0;
            long long collinear_diagonals = 0;

            for (auto const& [slope, count] : slope_counts) {
                total_diagonals += count;
                collinear_diagonals += (long long)count * (count - 1) / 2;
            }

            long long total_pairs = total_diagonals * (total_diagonals - 1) / 2;
            parallelograms += (total_pairs - collinear_diagonals);
        }

        return (int)(total_combinations - parallelograms);
    }
};