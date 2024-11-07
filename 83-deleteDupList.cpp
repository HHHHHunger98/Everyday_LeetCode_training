#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head)
        {
            return head;
        }
        
        ListNode *uni = head, *dup = head->next, *ans;
        while (dup!=nullptr)
        {
            if (uni->val == dup->val)
            {
                uni->next = nullptr;
                dup = dup->next;
            }else {
                uni->next = dup;
                uni = uni->next;
                dup = dup->next;
            }
            
        }
        return head;
    }
};