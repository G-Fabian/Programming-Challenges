// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;

        // Using Floyd's Cycle-Finding Algorithm we can find 
        // the node in the middle of linked list.
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != nullptr && fast != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of linked list with middle node
        // where the slow pointer stopped
        ListNode* rev = reverse(slow, prev);
        
        // Compare each value in the orginal linked list (cur) with reverse list (rev)
        // If each node is matches up to the half the linked list it is a palinrome
        // otherwise it is not a palindrome.
        while(rev != nullptr){
            if(rev->val != cur->val){
                return false;
            }
            rev = rev->next;
            cur = cur->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* cur, ListNode* prev){
        if(cur == nullptr)
            return prev;
        
        ListNode* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        return reverse(cur, prev);
    }

};