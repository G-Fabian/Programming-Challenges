/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 /* 141. Linked List Cycle
 Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        // To detect a cycle intialize two pointers a slow(one node behind fast) and a 
        // fast(one node in front of the slow pointer)
        // while traversing the linked list if there two pointers meet then 
        // there exist a cycle, however if the linked list ends there is no 
        // cycle. Note: Think of the turtle and rabbit story but they both meet at one point
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast) {
                return true;
            }
        }
        return false;
    }
};
