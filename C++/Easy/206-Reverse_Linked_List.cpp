// Given the head of a singly linked list, reverse the list, and return the reversed list

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* current = head;
        ListNode* previous = nullptr;
       
        // *** Iterative Solution 
        // While tranversing the list, the current node changes it's next node to the previous node
        // ultimately reversing the list once current reaches to end of list null.
        while(current != nullptr){
            ListNode* temp = current->next; // store address to the next node
            current->next = previous; // reverse pointer Ex: (null -> 1) to (null <- 1)
            previous = current; // advance previous node to current node
            current = temp; // advance current node to next node
        }
        return previous;

        // *** Recursive Solution 
        // return reverse(current, previous);;
    }


    ListNode* reverse(ListNode *current, ListNode *previous){
        // base case: end of linked list
        if(current == nullptr){
            return previous;
        }
        
        ListNode* temp = current->next; // store address to the next node
        current->next = previous; // reverse pointer Ex: (null -> 1) to (null <- 1)
        previous = current; // advance previous node to current node
        current = temp; // advance current node to next node
        return reverse(current, previous);// recursion
    };


};
