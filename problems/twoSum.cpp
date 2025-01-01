#include "problems.h"

namespace twoSum {
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map each number to the index it occurs
        unordered_map<int, int> valueToIndex;

        for (int i = 0; i < nums.size(); i++)
        {
            valueToIndex.emplace(nums[i], i);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // The number to get to target is the difference between the target and the number.
            int difference = target - nums[i];
            const auto matching = valueToIndex.find(difference);
            if (matching != valueToIndex.end() && matching->second != i)
            {
                return {min(matching->second, i), max(matching->second, i)};
            }
        }
        return {0, 0};
    }

    TEST(twoSum, T1) {
        vector<int> nums {2,7,11,15};
        vector<int> answer {0, 3};
        EXPECT_EQ(answer, twoSum(nums, 17));
    }

    TEST(twoSum, T2) {
        vector<int> nums {-1, 1};
        vector<int> answer {0, 1};
        EXPECT_EQ(answer, twoSum(nums, 0));
    }
    TEST(twoSum, T3) {
        vector<int> nums {-20,5,30};
        vector<int> answer {0, 1};
        EXPECT_EQ(answer, twoSum(nums, -15));
    }
}