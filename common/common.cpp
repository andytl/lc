
#include <list>
#include "common.h"

namespace common {
    using namespace std;

    list<int> convertToList(ListNode *node) {
        list<int> ret;
        while (node != nullptr) {
            ListNode *cNode = node;
            node = node->next;
            ret.push_back(cNode->val);
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

    void freeList(ListNode *node) {
        while (node != nullptr) {
            ListNode *cNode = node;
            node = node->next;
            delete cNode;
        }
    }
}