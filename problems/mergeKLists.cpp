#include <vector>
#include <queue>
#include <list>
#include "gtest/gtest.h"
#include "../common/common.h"

namespace mergeKLists {
    using namespace std;
    using namespace common;

    class Solution {
        struct LNComp {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<ListNode*, vector<ListNode*>, LNComp> listQ;
            ListNode* ret = nullptr;
            ListNode* cur = nullptr;
            for (auto list : lists) {
                if (list != nullptr) {
                    listQ.push(list);
                }
            }
            while (!listQ.empty()) {
                ListNode* next = listQ.top();
                listQ.pop();
                if (next->next) {
                    listQ.push(next->next);
                }

                if (ret == nullptr) {
                    ret = cur = next;
                } else {
                    cur->next = next;
                    cur = cur->next;
                }
                cur->next = nullptr;
            }
            return ret;
        }
    };
    Solution s;

    TEST(mergeKLists, T1) {
        vector<ListNode*> lists {
            convertFromList(list<int> {1, 4, 5}),
            convertFromList(list<int> {1, 3, 4}),
            convertFromList(list<int> {2, 6})
        };
        ListNode* resultLL = s.mergeKLists(lists);
        auto result = convertToList(resultLL);
        freeList(resultLL);

        EXPECT_EQ(result, (list<int> {1, 1, 2, 3, 4, 4, 5, 6}));
    }
}