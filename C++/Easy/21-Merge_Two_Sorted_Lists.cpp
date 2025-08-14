// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        
        // Traverse both list1 and list2, comparing the current nodes.
        // Append the node with the smaller value to 'curr' and move 
        // forward in that list.
        while(list1!=nullptr&&list2!=nullptr){
            if(list1->val < list2->val){
                cur->next = list1;
                list1 = list1 ->next;
            }
            else{
                cur->next = list2;
                list2 = list2 ->next;
            }
            cur = cur->next;
        }   

        // Append remaining node from either list
        (list1 == nullptr) ? cur->next=list2 : cur->next=list1;

        ListNode* result = ans->next;
        delete ans;

        return result;
    }
};