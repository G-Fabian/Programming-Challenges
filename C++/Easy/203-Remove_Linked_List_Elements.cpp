
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // // **** Two-Pointer Method ****

        // // Check if list is empty
        // if(head==nullptr) return head;
        
        // // Check for repeat values in list
        // while(head!=nullptr && head->val==val){
        //     head = head->next;
        // }
        
        // ListNode* cur = head;
        // ListNode* prev = nullptr;

        // // Tranverse through list and find unacceptable value
        // while(cur!=nullptr){
        //     // Current value matches input value
        //     // Redirect prev to skip cur node
        //     if(cur->val==val){
        //         prev->next = cur->next;
        //         cur = cur->next;
        //     }
        //     // Proceed to the next node
        //     else{
        //         prev = cur;
        //         cur = cur->next;        
        //     }
        // }

        // return head;

        // **** One Pointer Traversal ****

        ListNode* ans = new ListNode(0, head);
        ListNode* dummy = ans;

        // Dummy pointer will tranverse the linked list if value is found 
        // it will skip and assign its next node to the next valid node.
        while(dummy!=nullptr){
            // Note: Must check if nullptr on the left when using &&
            // otherwise program will crash when comparing dummy value to nullptr

            // Reassign dummy->next until valid node or nullptr
            while(dummy->next != nullptr && dummy->next->val == val){
                dummy->next = dummy->next->next;
            }
            
            // Move dummy node to new node if nullptr while loop ends
            dummy = dummy->next;
        }
        
        // Deallocate dynamic pointer
        ListNode* result = ans->next;
        delete ans;

        return result;
    }
};