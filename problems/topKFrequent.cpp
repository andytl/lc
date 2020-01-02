#include <vector>
#include "gtest/gtest.h"

namespace topKFrequent {
    using namespace std;

    class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            return {1};
        }
    };
    
    TEST(topKFrequent, SmokeTest) {
        Solution s;
        vector<int> expected {1, 1};
        EXPECT_EQ(expected, s.topKFrequent(vector<int>{1, 1}, 1));
    }
}