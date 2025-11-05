class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;

        for (int i = 0; i <= (int)nums.size() - k; i++) {
            unordered_map<int, int> count;

            for (int j = i; j < i + k; j++) {
                count[nums[j]]++;
            }

            if ((int)count.size() <= x) {
                int sum = 0;
                for (int j = i; j < i + k; j++)
                    sum += nums[j];
                res.push_back(sum);
            } 
            else {
                vector<pair<int, int>> pairs(count.begin(), count.end());

                sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
                    if (a.second == b.second) return a.first > b.first;
                    return a.second > b.second;
                });

                int cur_sum = 0;
                for (int j = 0; j < x; j++) {
                    cur_sum += pairs[j].first * pairs[j].second;
                }

                res.push_back(cur_sum);
            }
        }

        return res;
    }
};