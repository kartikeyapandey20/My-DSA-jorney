class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        
        int penalty = 0;
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }
        
        int minPenalty = penalty;
        int bestHour = 0;
        
        for (int j = 0; j < n; j++) {
            
            if (customers[j] == 'N') {
                penalty++;
            } else {
                penalty--;
            }
            
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j + 1;
            }
        }
        
        return bestHour;
    }
};