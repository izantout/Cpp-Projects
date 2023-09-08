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
    ListNode* deleteDuplicates(ListNode* head) {
       // Check if head is null or it only contains 1 element
       if(!head || !head->next){
           return head;
       }
       // Assign current to point to head
       ListNode* current = head;

       // While current-> next is not null
       while(current->next){
           // Check if the current value is the same as the next value
           if(current->val == current->next->val){
               // Create a temp ListNode
               ListNode* temp = current->next;
               // Have the current->next point to the one after
               current->next = current->next->next;
               // delete the duplicate ListNode
               delete temp;
           } else {
               // if they're not the same go to next node
               current = current->next;
           }
       }
       return head;
    }
};
