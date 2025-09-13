// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode();

    ListNode* ptr1 = list1;
    ListNode* ptr2 = list2;
    ListNode* newPtr = dummy;
    while (ptr1 != nullptr && ptr2 != nullptr) {
      if (ptr1->val > ptr2->val) {
        newPtr->next = ptr2;
        ptr2 = ptr2->next;
      } else {
        newPtr->next = ptr1;
        ptr1 = ptr1->next;
      }
      newPtr = newPtr->next;
    }

    if (ptr1 != nullptr) {
      newPtr->next = ptr1;
    }
    if (ptr2 != nullptr) {
      newPtr->next = ptr2;
    }

    return dummy->next;
  }
};