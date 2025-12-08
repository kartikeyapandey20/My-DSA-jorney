class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int cSquared = a * a + b * b;
                
                int c = sqrt(cSquared);
                
                if (c * c == cSquared && c <= n) {
                    count++;
                }
            }
        }
        
        return count;
    }
};