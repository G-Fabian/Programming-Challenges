// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

//  Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // ** Easy approach **
        ListNode *middle = head;
        
        // Count number of nodes in linked list
        int count = 0;
        while(middle != nullptr){
            middle = middle->next;
            count++;
        }

        // Calculate middle of linked list
        int mid_pos = count/2;
        
        // Reset linked list back to head
        middle = head;

        // Tranverse through linked list until middle position
        int pos = 0;
        while(middle != nullptr && pos < mid_pos){
            middle = middle->next;
            pos++;
        }

        return middle;

        // ** Difficult approach **
        // Floyd's Cycle-Finding Algorithm (Tortise & Hare Algorithm)
        // By the time the fast pointer reaches the end of linked list
        // the slow pointer will be at the middle of the list
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(slow != nullptr && fast != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};