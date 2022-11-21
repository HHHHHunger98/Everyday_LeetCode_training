#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class ListNode {

    public: 
        int val;
        ListNode* next;

        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val{x}, next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}

        static ListNode* listGenerator(int maxlen) {
            int len = (int)rand() % maxlen;
            ListNode* res = new ListNode(0);
            ListNode* tail = res;

            for(int i = len-1; i > 0; i--) {
                tail->val = (int)rand()%10;
                tail->next = new ListNode((int)rand()%10);
                tail = tail->next;
            }
            if(tail->val==0 && len!=0) tail->val++;
            return res;
        }

};

class Solution {

    public:
        static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int carry = 0;
            ListNode* res = new ListNode(0);
            ListNode* firstNumer = res;

            while(l1 != nullptr || l2 != nullptr || carry != 0) {
                int x = 0, y =0;
                if (l1 != nullptr) {
                    x = l1->val;
                    l1 = l1->next;
                }
                if (l2 != nullptr) {
                    y = l2->val;
                    l2 = l2->next;
                }
                res->next = new ListNode((x + y + carry) % 10);
                carry = (x + y + carry) / 10;
                res = res->next;
            }

            return firstNumer->next;
        }
};


int main(){

    int maxLen = 10;
    srand((unsigned)time(NULL));
    ListNode* l1 = ListNode::listGenerator(maxLen);
    ListNode* l2 = ListNode::listGenerator(maxLen);
    ListNode* l3 = Solution::addTwoNumbers(l1,l2);
    while(l1!=nullptr) {
        cout<<l1->val;
        l1 = l1->next;
    }
    cout<<endl;
    while(l2!=nullptr) {
        cout<<l2->val;
        l2 = l2->next;
    }
    cout<<endl;
    while(l3!=nullptr) {
        cout<<l3->val;
        l3 = l3->next;
    }
    return 0;
}