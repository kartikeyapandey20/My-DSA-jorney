class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        
        vector<int> seatPos;
        for (int i = 0; i < corridor.length(); i++) {
            if (corridor[i] == 'S') {
                seatPos.push_back(i);
            }
        }
        
        int totalSeats = seatPos.size();
        
        if (totalSeats == 0 || totalSeats % 2 == 1) {
            return 0; 
        }
        
        if (totalSeats == 2) {
            return 1; 
        }
        
        long long ways = 1;
        
        for (int i = 1; i < totalSeats / 2; i++) {
            int secondSeatOfSection = seatPos[2 * i - 1];
            
            int firstSeatOfNextSection = seatPos[2 * i];
            
            int choices = firstSeatOfNextSection - secondSeatOfSection;
            
            ways = (ways * choices) % MOD;
        }
        
        return ways;
    }
};