#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>
#include "gtest/gtest.h"

namespace topKFrequent {
    using namespace std;

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
                if (maxes.size() > k) {
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
        EXPECT_EQ(expected, s.topKFrequent(vector<int>{1,1,1,2,2,3}, 2));
    }
    TEST(topKFrequent, T2) {
        vector<int> expected {1};
        EXPECT_EQ(expected, s.topKFrequent(vector<int>{1}, 1));
    }
}