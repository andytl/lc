#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>
#include <list>
#include "gtest/gtest.h"

namespace mergeKLists {
    using namespace std;

    // Check for leaks... assume single thread.
    int leakCount = 0;
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {leakCount++;}
        ~ListNode() {leakCount--;}
    };

    list<int> convertToList(ListNode *node) {
        list<int> ret;
        while (node != nullptr) {
            ListNode *cNode = node;
            node = node->next;
            ret.push_back(cNode->val);
            delete cNode;
        }
        return ret;
    }
    ListNode* convertFromList(list<int> nodes) {
        ListNode* ret = nullptr;
        ListNode* cur = nullptr;
        for (auto &n : nodes) {
            if (ret == nullptr) {
                ret = cur = new ListNode(n);
            } else {
                cur->next = new ListNode(n);
                cur = cur->next;
            }
        }
        return ret;
    }

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
        auto result =
            convertToList(
                s.mergeKLists(lists)
            );

        EXPECT_EQ(result, (list<int> {1, 1, 2, 3, 4, 4, 5, 6}));
        EXPECT_EQ(leakCount, 0);
    }
}