#include "problems.h"

namespace reverseList {
    class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* result = nullptr;
            while (head != nullptr)
            {
                ListNode* next = head->next;
                head->next = result;
                result = head;
                head = next;
            }
            return result;
        }
    };
    Solution s;

    TEST(reverseList, T1) {
        ListNode* resultLL = s.reverseList(convertFromList(list<int> {1, 2, 3, 4, 5}));
        auto result = convertToList(resultLL);
        freeList(resultLL);

        EXPECT_EQ(result, (list<int> {5, 4, 3, 2, 1}));
    }
}