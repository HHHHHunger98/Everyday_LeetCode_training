#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode();
        ListNode* tmp = res;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        while(cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val > cur2->val) {
                tmp->next = new ListNode(cur2->val);
                cur2 = cur2->next;
            }else{
                tmp->next = new ListNode(cur1->val);
                cur1 = cur1->next;
            }
            tmp = tmp->next;
        }
        if (cur1 == nullptr)
        {
            tmp->next = cur2;
        }else{
            tmp->next = cur1;
        }
        
        return res->next;
    }
};

int main() {
    return 0;
}