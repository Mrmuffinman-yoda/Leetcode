
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* ptr = head;
    ListNode* previousNode = nullptr;
    ListNode* nextNode = nullptr;

    while (ptr != nullptr) {
      // set next node

      nextNode = ptr->next;
      ptr->next = previousNode;
      previousNode = ptr;
      ptr = nextNode;
    }
    return previousNode;
  }
};