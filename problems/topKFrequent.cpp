#include "problems.h"

namespace topKFrequent {
    class Solution {
        using IP = pair<int,int>;
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            // Defaults to pair < which is first < second.
            // Reverse to keep smallest on top
            priority_queue<IP, vector<IP>, greater<IP>> maxes;
            unordered_map<int, int> counts;

            for (auto &num : nums) {
                counts[num]++;
            }
            for (auto &count : counts) {
                maxes.emplace(count.second, count.first);
                if (maxes.size() > static_cast<size_t>(k)) {
                    maxes.pop();
                }
            }

            vector<int> result;
            while (!maxes.empty()) {
                result.push_back(maxes.top().second);
                maxes.pop();
            }
            reverse(result.begin(), result.end());

            return result;
        }
    };
    Solution s;

    TEST(topKFrequent, T1) {
        vector<int> expected {1, 2};
        vector<int> iList {1,1,1,2,2,3};
        EXPECT_EQ(expected, s.topKFrequent(iList, 2));
    }
    TEST(topKFrequent, T2) {
        vector<int> expected {1};
        vector<int> iList {1};
        EXPECT_EQ(expected, s.topKFrequent(iList, 1));
    }
}