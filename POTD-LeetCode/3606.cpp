class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string, string>> validCoupons; // {businessLine, code}
        
        map<string, int> businessOrder = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        
        for (int i = 0; i < n; i++) {
            if (!isActive[i]) continue;
            
            if (businessOrder.find(businessLine[i]) == businessOrder.end()) continue;
            
            if (code[i].empty()) continue;
            
            bool validCode = true;
            for (char ch : code[i]) {
                if (!isalnum(ch) && ch != '_') {
                    validCode = false;
                    break;
                }
            }
            if (!validCode) continue;
            
            validCoupons.push_back({businessLine[i], code[i]});
        }
        
        sort(validCoupons.begin(), validCoupons.end(), [&](const auto& a, const auto& b) {
            if (businessOrder[a.first] != businessOrder[b.first]) {
                return businessOrder[a.first] < businessOrder[b.first];
            }
            return a.second < b.second;
        });
        
        vector<string> result;
        for (auto& [bl, c] : validCoupons) {
            result.push_back(c);
        }
        
        return result;
    }
};