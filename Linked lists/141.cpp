
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  bool hasCycle(ListNode* head) {
    ListNode* ptr1;
    ListNode* ptr2;
    if (head != nullptr && head->next != nullptr) {
      ptr1 = head;
      ptr2 = head->next;
    } else {
      return false;
    }

    while (ptr2->next != nullptr && ptr2->next->next != nullptr) {
      if (ptr1 == ptr2) {
        return true;
      }
      ptr1 = ptr1->next;
      ptr2 = ptr2->next->next;
    }
    return false;
  }
};