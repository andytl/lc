#ifndef COMMON_H
#define COMMON_H

#include <list>

namespace common {

    using namespace std;

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    list<int> convertToList(ListNode *node);
    ListNode* convertFromList(list<int> nodes);
    void freeList(ListNode *node);

}

#endif